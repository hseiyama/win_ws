#include <windows.h>
#include <time.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    int hr, mn, sec, ret;
    char str[256];
    char *str_org = "��������%3d��%3d��%3d�b�ł�";
    struct tm *mytime;
    time_t long_time;
    
    while(1) {
        time(&long_time);
        mytime = localtime(&long_time);
        hr = mytime->tm_hour;
        mn = mytime->tm_min;
        sec = mytime->tm_sec;
        sprintf(str, str_org, hr, mn, sec);

        ret = MessageBox(NULL,
            (LPCSTR)str,
            (LPCSTR)"�L�ł��킩��v���O���~���O",
            MB_OKCANCEL);
        if (ret == IDCANCEL)
            break;
    }
    return 0;
}
