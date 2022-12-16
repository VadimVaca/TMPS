// MainFile.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "MainFile.h"
#include "shellapi.h"
#include <string>
#define MAX_LOADSTRING 100
_TCHAR* addres;
int ll;
POINT pt;
int GetAddres(char Level)
{
    _TCHAR tmp[200];
    char Lev[] = "\\Level1.exe";
    Lev[6] = Level;
    int len = GetCurrentDirectory(200, tmp);
    addres = new _TCHAR[len + 12];
    for (int o = 0; o < len ; o++)
        addres[o] = tmp[o];
    for (int i = 0; i < 12; i++)
        addres[i + len ] = Lev[i];

    return len + 12;

}

class PosConvert
{
    int xstart;
    int ystart;

public:
    PosConvert(int x, int y)
    {
        xstart = x;
        ystart = y;
    }
    int XLine(POINT c, int bonus) {
        return (c.x - xstart) / (8+bonus);
    }
    int YLine(POINT c, int bonus) {
        return (c.y - ystart) / (16+bonus);
    }
};

class BaseLevel;
class Mediator {
public:
    virtual void Notify(BaseLevel* sender, std::string event) const = 0;
};

class BaseLevel {
protected:
    Mediator* mediator_;

public:
    BaseLevel(Mediator* mediator = nullptr) : mediator_(mediator) {
    }
    void set_mediator(Mediator* mediator) {
        this->mediator_ = mediator;
    }
};


class Level1 : public BaseLevel {
public:
    void DoA(HWND hWnd) {
        this->mediator_->Notify(this, "A");
        _TCHAR* filename;
        _TCHAR* windowTitle;
        GetAddres('1');
        filename = addres;
        windowTitle = new _TCHAR[5];
        windowTitle[0] = 's';
        windowTitle[1] = 't';
        windowTitle[2] = 'a';
        windowTitle[3] = 'r';
        windowTitle[4] = 't';
        
        ShellExecute(hWnd, _T("open"), filename, NULL, NULL, SW_SHOW);
    }
    void DoB() {
        HWND hwnd;
        hwnd = FindWindow(NULL, _T("start"));
        if (hwnd != NULL)
        {
            PostMessage(hwnd, WM_DESTROY, 0, 0);
        }
        
    }
};

class Level2 : public BaseLevel {
public:
    void DoC(HWND hWnd) {
        this->mediator_->Notify(this, "C");

        _TCHAR* filename;
        _TCHAR* windowTitle;
        GetAddres('2');
        filename = addres;
        windowTitle = new _TCHAR[6];
        windowTitle[0] = 'L';
        windowTitle[1] = 'e';
        windowTitle[2] = 'v';
        windowTitle[3] = 'e';
        windowTitle[4] = 'l';
        windowTitle[5] = '2';
        
        ShellExecute(hWnd, _T("open"), filename, NULL, NULL, SW_SHOW);
        
        
    }
    void DoD() {
        HWND hwnd;
            hwnd = FindWindow(NULL, _T("Level2"));
            if (hwnd != NULL)
            {
                PostMessage(hwnd, WM_DESTROY, 0, 0);
            }
      
       
    }
};
class Level3 : public BaseLevel {
public:
    void DoE(HWND hWnd) {
        this->mediator_->Notify(this, "E");
        _TCHAR* filename;
        _TCHAR* windowTitle;
        GetAddres('3');
        filename = addres;
        windowTitle = new _TCHAR[6];
        windowTitle[0] = 'L';
        windowTitle[1] = 'e';
        windowTitle[2] = 'v';
        windowTitle[3] = 'e';
        windowTitle[4] = 'l';
        windowTitle[4] = '3';
        
        ShellExecute(hWnd, _T("open"), filename, NULL, NULL, SW_SHOW);

        
    }
    void DoF() {
        HWND hwnd;
     
            hwnd = FindWindow(NULL, _T("Level3"));
            if (hwnd != NULL)
            {
                PostMessage(hwnd, WM_DESTROY, 0, 0);
            }
       
        
    }
};


class ConcreteMediator : public Mediator {
private:
    Level1* Level1_;
    Level2* Level2_;
    Level3* Level3_;

public:
    ConcreteMediator(Level1* c1, Level2* c2, Level3* c3) : Level1_(c1), Level2_(c2), Level3_(c3){
        this->Level1_->set_mediator(this);
        this->Level2_->set_mediator(this);
        this->Level3_->set_mediator(this);
    }
    void Notify(BaseLevel* sender, std::string event) const override {
        _TCHAR u = event[0];
        switch (u) {
            case 'A':
                this->Level1_->DoB();
                this->Level2_->DoD();
                this->Level3_->DoF();
                break;
            case 'B':

                break;
            case 'C':
                this->Level1_->DoB();
                this->Level2_->DoD();
                this->Level3_->DoF();
                break;
            case 'D':

                break;
            case 'E':
                this->Level1_->DoB();
                this->Level2_->DoD();
                this->Level3_->DoF();
                break;
            case 'F':

                break;
            default:    break;
        }
        
        
    }
};
Level1* c1 = new Level1;
Level2* c2 = new Level2;
Level3* c3 = new Level3;
ConcreteMediator* mediator = new ConcreteMediator(c1, c2, c3);
// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MAINFILE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MAINFILE));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINFILE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MAINFILE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_LBUTTONDOWN:
        if (GetCursorPos(&pt))
        {

            ScreenToClient(hWnd, &pt);
            PosConvert converter(150,250);
            switch (converter.YLine(pt, 35))
            {
                case 0:
                    c1->DoA(hWnd);
                    break;
                case 1:
                    c2->DoC(hWnd);
                    break;
                case 2:
                    c3->DoE(hWnd);
                    break;
                default:
                    break;
            }
          
            InvalidateRect(hWnd, NULL, true);
        }
        break;
    
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            TextOut(hdc, 150, 150, _T("Welcome to main menu!"), 21);
            TextOut(hdc, 150, 210, _T("Select Level you want to try by click"), 37);
            TextOut(hdc, 150, 250, _T("1. Level1. ADD and SUBTRACT(+ and -) operations"), 47);
            TextOut(hdc, 150, 300, _T("2. Level2. MULTIPLY and DIVIDE(* and /) operations"), 50);
            TextOut(hdc, 150, 350, _T("3. Level3. Some EXPONENT (^) operations"), 39);
            TextOut(hdc, 150, 400, _T("Future development"), 18);
            TextOut(hdc, 100, 100, addres, ll);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
