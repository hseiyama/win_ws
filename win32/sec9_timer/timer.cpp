//        timer.cpp

#include <windows.h>
#include "timer.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL InitApp(HINSTANCE, LPCSTR);
BOOL InitInstance(HINSTANCE, LPCSTR, int);

int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst,
                   LPSTR lpsCmdLine, int nCmdShow)
{
    MSG msg;
    char szClassName[] = "timer";   //ウィンドウクラス
    
    if (!hPrevInst) {
        if (!InitApp(hCurInst, szClassName))
            return FALSE;
    }
    if (!InitInstance(hCurInst, szClassName, nCmdShow)) {
        return FALSE;
    }
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

//ウィンドウ・クラスの登録　BOOLはTRUEかFALSEしか返さないの意味

BOOL InitApp(HINSTANCE hInst, LPCSTR szClassName)
{
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;       //プロシージャ名
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInst;           //インスタンス
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = (LPCSTR)"TIMERMENU";  //メニュー名
    wc.lpszClassName = szClassName;
    return (RegisterClass(&wc));
}

//ウィンドウの生成

BOOL InitInstance(HINSTANCE hInst, LPCSTR szClassName, int nCmdShow)
{
    HWND hWnd;

    hWnd = CreateWindow(szClassName,
            (LPCSTR)"タイマー",     //タイトルバーにこの名前が表示されます
            WS_OVERLAPPEDWINDOW,    //ウィンドウの種類
            CW_USEDEFAULT,          //Ｘ座標
            CW_USEDEFAULT,          //Ｙ座標
            CW_USEDEFAULT,          //幅
            CW_USEDEFAULT,          //高さ
            NULL,                   //親ウィンドウのハンドル、親を作るときはNULL
            NULL,                   //メニューハンドル、クラスメニューを使うときはNULL
            hInst,                  //インスタンスハンドル
            NULL);
    if (!hWnd)
        return FALSE;
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    return TRUE;
}

//ウィンドウプロシージャ

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    int id;
    switch (msg) {
        case WM_CREATE:
            if(SetTimer(hWnd, ID_MYTIMER, 3000, NULL) == 0) {
                MessageBox(hWnd,
                    (LPCSTR)"タイマー失敗！",
                    (LPCSTR)"失敗",
                    MB_OK);
            } else {
                MessageBox(hWnd,
                    (LPCSTR)"タイマー成功！",
                    (LPCSTR)"成功",
                    MB_OK | MB_ICONEXCLAMATION);
            }
            break;
        case WM_TIMER:
            KillTimer(hWnd, ID_MYTIMER);
            id = MessageBox(hWnd,
                (LPCSTR)"タイマーを再発行しますか？",
                (LPCSTR)"タイマー終了の確認",
                MB_YESNO);
            if (id == IDYES) {
                SetTimer(hWnd, ID_MYTIMER, 3000, NULL);
            }
            break;
        case WM_COMMAND:
            switch (LOWORD(wp)) {
                case IDM_END:
                    SendMessage(hWnd, WM_CLOSE, 0, 0L);
                    break;
                default:
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return (DefWindowProc(hWnd, msg, wp, lp));
    }
    return 0L;
}
