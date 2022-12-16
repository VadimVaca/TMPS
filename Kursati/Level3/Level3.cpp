// Level3.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Level3.h"
#include <iostream>
#include <chrono>
#define MAX_LOADSTRING 100
POINT pt;
int curEnt = 0;
int rez = -1;
bool help = 0;
bool zn = 0;
bool mode = 0;
bool calc = 0;
_TCHAR mainstr[200] = { '3','^','0','+','1','^','1','+','9','^','0','+','6','^','0','=' };
int msLen = _tcslen(mainstr);
int convi(int zn, _TCHAR* res)
{
    char tool[10] = { " " };
    int l = sprintf_s(tool, 10, "%d", zn);
    for (int i = 0; i < 10; i++)
        if (i < l)
            res[i] = tool[i];
        else
            if (i == l)
                res[i] = '.';
            else
                res[i] = '0';
    return l;
}
void crutches(int z, int k)
{
    _TCHAR tmp[10];
    int l=convi(z, tmp);
    for (int i = 0; i < l; i++)
    {
        mainstr[msLen] = tmp[i];
        msLen++;
    }
    mainstr[msLen] = '^';
    msLen ++;
    l = convi(k, tmp);
    for (int i = 0; i < l; i++)
    {
        mainstr[msLen] = tmp[i];
        msLen++;
    }
}
class Problem
{
public:
    virtual void DisplayProblem() {};
    virtual void Resolve() {};
    virtual bool AnswerCheck() { return 0; };
    virtual void ShowAnswer() {};
    virtual void Progress() {};
    virtual void ShowStep() {};
    virtual ~Problem() {};
};
class Level3 : public Problem
{
    int* Arguments;
    char* Actions;
    int oCount;
    _TCHAR searchC[10];
    int searchI;
    _TCHAR numeric[200];
    int numericLen = 0;
public:
    Level3(int Arg[], char Act[], int count)
    {
        Arguments = new int[count];
        Actions = new char[count];
        oCount = count;
        for (int i = 0; i < count; i++)
        {
            Arguments[i] = Arg[i];
            if (i != count - 1)
                Actions[i] = Act[i];
            else
                Actions[i] = '=';
        }
    }
    void convP(int pos)
    {
        _TCHAR numC[10];
        numericLen = 0;
        for (int i = 0; i < pos; i++)
        {
            int _len = convi(Arguments[i], numC);
            for (int p = 0; p < _len; p++)
            {
                numeric[numericLen] = numC[p];
                numericLen++;
            }
            numeric[numericLen] = Actions[i];
            numericLen++;
        }
        numeric[numericLen-1] = '=';
    }
    void Resolve(int actCount) {
        int rez = 0;
        rez = Arguments[0];
        for (int i = 0; i < actCount; i++)
        {

            switch (Actions[i]) {
            case '+': rez += Arguments[i + 1]; break;
            case '-': rez -= Arguments[i + 1]; break;
            case '=': searchI = rez; convi(rez, searchC);  break;
            }
        }
        searchI = rez; convi(rez, searchC);
    }
    bool AnswerCheck(int zn) {
        Resolve(oCount);
        if (searchI == zn)
            return 1;
        else
            return 0;
    }
    void DisplayProblem(HDC hdc) {        
        TextOut(hdc, 100, 100, mainstr, msLen);

    }
    void DisplayHelp(HDC hdc) {
        convP(oCount);
        TextOut(hdc, 100, 130, numeric, numericLen-1);

    }
    void ShowAnswer(HDC hdc) {
        ShowStep(hdc, oCount);
    }
    void ShowStep(HDC hdc, int pos) {
        for (int i = 2; i <= pos; i++)
        {
            Resolve(i-1);
            convP(i);
            int _rez = searchI;
            int len = 0;
            do {
                len++;
                _rez /= 10;
            } while (_rez);
            if (searchI < 0)
                len++;
            TextOut(hdc, 100, 155 + (i-1) * 25, numeric, numericLen);
            TextOut(hdc, 100 + numericLen * 8, 155 + (i-1) * 25, searchC, len);
        }
    }
    int getArg(int n) { return Arguments[n]; }
    int getAct(int n) { return Actions[n]; }
    int getLEn() { return numericLen; }
    Level3& operator=(Level3& other);
    void Progress() {}
    //~Level1() { }
};
Level3& Level3::operator=(Level3& another) { //присваивание
    if (this == &another)
        return *this;
    Arguments = another.Arguments;
    Actions = another.Actions;
    oCount = another.oCount;
}
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
    LoadStringW(hInstance, IDC_LEVEL3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LEVEL3));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LEVEL3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LEVEL3);
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

int mass[5] = { 1,1,1,1 };
char str[4] = { '+','+','+' };
Level3 First(mass, str, 4);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    srand(time(NULL));
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
            if (pt.x > 799 && pt.x < 851 && pt.y>124 && pt.y < 151)
                mode = 0;
            if (pt.x > 849 && pt.x < 901 && pt.y>124 && pt.y < 151)
                mode = 1;
            InvalidateRect(hWnd, NULL, true);
        }
        break;
    case WM_KEYDOWN:
    {
        switch (wParam)
        {

        case VK_SUBTRACT:
            zn = 1;
            break;
        case VK_OEM_MINUS:
            zn = 1;
            break;
        case VK_OEM_PLUS:
            zn = 0;
            break;
        case VK_ADD:
            zn = 0;
            break;
        case 0x30:
            if (curEnt < 100000000)
                curEnt = curEnt * 10 + 0;
            rez = -1;
            break;
        case 0x31:
            if (curEnt < 100000000)
                curEnt = curEnt * 10 + 1;
            rez = -1;
            break;
        case 0x32:
            if (curEnt < 100000000)
                curEnt = curEnt * 10 + 2;
            rez = -1;
            break;
        case 0x33:
            if (curEnt < 100000000)
                curEnt = curEnt * 10 + 3;
            rez = -1;
            break;
        case 0x34:
            if (curEnt < 100000000)
                curEnt = curEnt * 10 + 4;
            rez = -1;
            break;
        case 0x35:
            if (curEnt < 100000000)
                curEnt = curEnt * 10 + 5;
            rez = -1;
            break;
        case 0x36:
            if (curEnt < 100000000)
                curEnt = curEnt * 10 + 6;
            rez = -1;
            break;
        case 0x37:
            if (curEnt < 100000000)
                curEnt = curEnt * 10 + 7;
            rez = -1;
            break;
        case 0x38:
            if (curEnt < 100000000)
                curEnt = curEnt * 10 + 8;
            rez = -1;
            break;
        case 0x39:
            if (curEnt < 100000000)
                curEnt = curEnt * 10 + 9;
            rez = -1;
            break;
        case VK_RETURN:
            if (zn)
                curEnt *= -1;
            rez = (int)First.AnswerCheck(curEnt);
            if (curEnt < 0)
                curEnt *= -1;
            break;
        case VK_BACK:
            if (!curEnt)
                zn = 0;
            curEnt /= 10;
            break;
        case VK_SPACE:
        {
            msLen = 0;           
            int k = rand() % (15 + mode * 25) + 1;
            int n = rand() % (3 + (k < 16) * mode  + (k<11) );
            int i = rand() % 6 + 2 + 2 * mode;
            crutches(k, n);
            int* mas = new int[i];
            char* ac = new char[i - 1];
            mas[0] = pow(k, n);
            for (int j = 0; j < i - 1; j++)
            {
                k = rand() % (15 + mode * 25) + 1;
                n = rand() % (3 + (k < 16) * mode  + (k < 11) );

                int act = rand() % 2;
                switch (act) {
                case 0: ac[j] = '+'; break;
                case 1: ac[j] = '-'; break;
                }
                mainstr[msLen] = ac[j];
                msLen++;
                mas[j + 1] = pow(k, n);
                crutches(k, n);

            }
            mainstr[msLen] = '=';
            msLen++;
            Level3 Second(mas, ac, i);
            First = Second;
            rez = -1;
            help = 0;
            curEnt = 0;
            zn = 0;
            calc = 0;
            InvalidateRect(hWnd, NULL, true);
        }
        break;
        case VK_F2:
            help = 1;
            break;


        case VK_F3:
            help = 1;
            calc = 1;
            break;
        }
        InvalidateRect(hWnd, NULL, true);
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        HBRUSH hBrush;
        TextOut(hdc, 800, 100, _T("Easy    Hard"), 12);
        Rectangle(hdc, 800, 125, 850, 150);
        Rectangle(hdc, 800 + 50, 125, 850 + 50, 150);
        hBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(hdc, hBrush);
        Rectangle(hdc, 800 + 50 * (int)mode, 125, 850 + 50 * (int)mode, 150);
        DeleteObject(hBrush);
        First.DisplayProblem(hdc);
        if (help) {
            First.DisplayHelp(hdc);
            if (calc)
                First.ShowAnswer(hdc);
        }
        _TCHAR tmp[10];
        int tmpLen = convi(curEnt, tmp);
        if (zn)
            TextOut(hdc, 100 + msLen * 8, 100, _T("-"), 1);
        TextOut(hdc, 108 + msLen * 8, 100, tmp, tmpLen);
        if (rez == 1)
            TextOut(hdc, 100 + msLen * 8 + 55, 100, _T("Accepted!"), 9);
        else
            if (rez == 0)
                TextOut(hdc, 100 + msLen * 8 + 85, 100, _T("False!"), 6);
            else
                TextOut(hdc, 100 + msLen * 8 + 85, 100, _T("Press ENTER to check your answer!"), 33);
        TextOut(hdc, 50, 30, _T("Press SPACE to get another example!"), 35);
        TextOut(hdc, 50, 60, _T("Press F2 to check your exponent calculations!"), 45);
        TextOut(hdc, 50+45*8, 60, _T("Press F3 to get major help!"), 27);
        TextOut(hdc, 50, 5, _T("Use 0-9,-,+ to write your answer!"), 33);
        TextOut(hdc, 300, 5, _T("Press BACKSPACE to erase your input!"), 36);

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