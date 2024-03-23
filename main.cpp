// random-number-generator.cpp : ����Ӧ�ó������ڵ㡣
//

#include "framework.h"
#include "random-number-generator.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���:
HINSTANCE hInst;                                // ��ǰʵ��
char szTitle[MAX_LOADSTRING]="Random Number Generator";                  // �������ı�
char szWindowClass[MAX_LOADSTRING]="RANDOMNUMBERGENERATOR";            // ����������

//HDC hdc;
//PAINTSTRUCT ps;

// �˴���ģ���а����ĺ�����ǰ������:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: �ڴ˴����ô��롣
    init();


    // ��ʼ��ȫ���ַ���
    //LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    //LoadStringW(hInstance, IDC_RANDOMNUMBERGENERATOR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��:
    if (!InitInstance (hInstance, nShowCmd))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RANDOMNUMBERGENERATOR));

    MSG msg;

    // ����Ϣѭ��:
    while (GetMessage(&msg, NULL, 0, 0))
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
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RANDOMNUMBERGENERATOR));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    //wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_RANDOMNUMBERGENERATOR);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassEx(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   HWND hWnd = CreateWindowA(szWindowClass, szTitle, WS_POPUP|WS_CAPTION|WS_DLGFRAME|WS_SYSMENU|WS_MINIMIZEBOX,
      CW_USEDEFAULT, 0, 400, 400, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   //hdc = BeginPaint(hWnd, &ps);
   //SendMessageA(hWnd, PAINT_REFRESH, NULL, NULL);
   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_PAINT    - ����������
//  WM_DESTROY  - �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �����˵�ѡ��:
            switch (wmId)
            {
            /*
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;*/
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
    {
        if (1) {
            
           
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: �ڴ˴����ʹ�� hdc ���κλ�ͼ����...
            HPEN brush = CreatePen(PS_SOLID, 75, RGB(0, 255, 0));
            HPEN innerbrush = CreatePen(PS_SOLID, 70, RGB(255, 255, 255));
            HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
            HGDIOBJ obj = SelectObject(hdc, brush);
            MoveToEx(hdc, 150, 150, NULL);
            LineTo(hdc, 250, 150);
            SelectObject(hdc, innerbrush);
            MoveToEx(hdc, 150, 150, NULL);
            LineTo(hdc, 250, 150);
            LPCSTR str = "��ȡ";
            char Res_num[10] = { '?','?',0 };
            char tmpstr[10];
            //char Res_num[10];
            if (p != -1) {
                
                int i = 0, j = 0;
                while (p) {
                    tmpstr[i] = p % 10;
                    p /= 10;
                    i++;
                }
                while (i) {
                    i--;
                    Res_num[j] = tmpstr[i] + '0';
                    j++;
                }
                Res_num[j] = 0;
            }
            RECT rect;
            RECT ResRect;
            HFONT hFont = CreateFontA(48, 0, 0, 20, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, "Impact");

            HFONT hNum = CreateFontA(64, 0, 0, 20, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, "Impact");

            SelectObject(hdc, hFont);
            //SetTextColor(hdc, RGB(255, 255, 255));
            SetRect(&rect, 150, 125, 250, 175);
            SetRect(&ResRect, 150, 200, 250, 325);
            FillRect(hdc, &ResRect, hBrush);
            //GetClientRect(hWnd, &rect);
            //BeginPath(hdc);
            DrawText(hdc, str, -1, &rect, DT_NOCLIP | DT_CENTER);
            SelectObject(hdc, hNum);
            LPCSTR tmp = num2str(p);
            //MessageBoxA(NULL, tmp, NULL, NULL);
            DrawTextA(hdc, Res_num, -1, &ResRect, DT_NOCLIP | DT_CENTER);
            //SetWindowTextA(hWnd, Res_num);
            //EndPath(hdc);
            //DrawText(hdc, str, -1, &rect, DT_NOCLIP);
            //SelectClipPath(hdc, RGN_AND);
            //FillRect(hdc, &rect,hBrush);


            /*for (int i = 1; i <= 400; i++) {
                for (int j = 1; j <= 400; j++) {


                }
            }*/
            EndPaint(hWnd, &ps);
            /*if (KEY_DOWN(1)) {
                POINT Coord;
                GetCursorPos(&Coord);
                ScreenToClient(hWnd, &Coord);
                if (Coord.x > 125 && Coord.x < 275 && Coord.y > 125 && Coord.y < 175) {
                    //MessageBoxExA(hWnd,"Click","Caption",MB_ICONINFORMATION);
                    MessageBoxA(hWnd,"Click","Caption",MB_ICONINFORMATION);
                }
                MessageBoxA(hWnd, "Click", "Caption", MB_ICONINFORMATION);
            }*/
        }
        else if (0) {

        }

    }
    break;
        //MessageBoxA(hWnd, "Message Received!", "message", NULL);
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        if (KEY_DOWN(1)) {
            POINT Coord;
            GetCursorPos(&Coord);
            ScreenToClient(hWnd, &Coord);
            if (Coord.x > 125 && Coord.x < 275 && Coord.y > 125 && Coord.y < 175) {
                //MessageBoxExA(hWnd,"Click","Caption",MB_ICONINFORMATION);
                //MessageBoxA(hWnd, "Click", "Caption", MB_ICONINFORMATION);
                srand(clock());
                int tmp = rand();
                p = Rand_Min + (tmp % Rand_Mod);
                //RECT wndrect;
                //SetRect(&wndrect, 0, 0, 400, 400);
                RedrawWindow(hWnd, NULL, NULL, RDW_INTERNALPAINT|RDW_INVALIDATE);
                //SendMessageA(hWnd, PAINT_REFRESH, NULL, NULL);
            }
            //MessageBoxA(hWnd, "Click", "Caption", MB_ICONINFORMATION);
        }
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

/* �����ڡ������Ϣ�������
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
}*/

