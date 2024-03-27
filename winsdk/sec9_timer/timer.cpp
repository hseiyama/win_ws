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
    char szClassName[] = "timer";   //�E�B���h�E�N���X
    
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

//�E�B���h�E�E�N���X�̓o�^�@BOOL��TRUE��FALSE�����Ԃ��Ȃ��̈Ӗ�

BOOL InitApp(HINSTANCE hInst, LPCSTR szClassName)
{
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;       //�v���V�[�W����
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInst;           //�C���X�^���X
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszMenuName = (LPCSTR)"TIMERMENU";  //���j���[��
    wc.lpszClassName = szClassName;
    return (RegisterClass(&wc));
}

//�E�B���h�E�̐���

BOOL InitInstance(HINSTANCE hInst, LPCSTR szClassName, int nCmdShow)
{
    HWND hWnd;

    hWnd = CreateWindow(szClassName,
            (LPCSTR)"�^�C�}�[",     //�^�C�g���o�[�ɂ��̖��O���\������܂�
            WS_OVERLAPPEDWINDOW,    //�E�B���h�E�̎��
            CW_USEDEFAULT,          //�w���W
            CW_USEDEFAULT,          //�x���W
            CW_USEDEFAULT,          //��
            CW_USEDEFAULT,          //����
            NULL,                   //�e�E�B���h�E�̃n���h���A�e�����Ƃ���NULL
            NULL,                   //���j���[�n���h���A�N���X���j���[���g���Ƃ���NULL
            hInst,                  //�C���X�^���X�n���h��
            NULL);
    if (!hWnd)
        return FALSE;
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    return TRUE;
}

//�E�B���h�E�v���V�[�W��

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    int id;
    switch (msg) {
        case WM_CREATE:
            if(SetTimer(hWnd, ID_MYTIMER, 3000, NULL) == 0) {
                MessageBox(hWnd,
                    (LPCSTR)"�^�C�}�[���s�I",
                    (LPCSTR)"���s",
                    MB_OK);
            } else {
                MessageBox(hWnd,
                    (LPCSTR)"�^�C�}�[�����I",
                    (LPCSTR)"����",
                    MB_OK | MB_ICONEXCLAMATION);
            }
            break;
        case WM_TIMER:
            KillTimer(hWnd, ID_MYTIMER);
            id = MessageBox(hWnd,
                (LPCSTR)"�^�C�}�[���Ĕ��s���܂����H",
                (LPCSTR)"�^�C�}�[�I���̊m�F",
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
