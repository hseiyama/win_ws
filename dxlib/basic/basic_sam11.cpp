#include <DxLib.h>
#include <stdio.h>

int mouseX = 0;//マウス座標
int mouseY = 0;//マウス座標

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);//非全画面にセット
    SetGraphMode(640, 480, 32);//画面サイズ指定
    SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定
    if (DxLib_Init() == 1){ return -1; }//初期化に失敗時にエラーを吐かせて終了

    int handle = LoadGraph("sample.png");

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();//裏画面消す
        SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

        GetMousePoint(&mouseX, &mouseY); //マウス座標更新

        double exrate = mouseX / 100.0;
        double angle = mouseY / 100.0;

        DrawFormatString(20, 20, GetColor(255, 255, 255), "mouseX:%d", mouseX);
        DrawFormatString(20, 40, GetColor(255, 255, 255), "mouseY:%d", mouseY);
        DrawFormatString(20, 60, GetColor(255, 255, 255), "exrate:%f", exrate);
        DrawFormatString(20, 80, GetColor(255, 255, 255), "angle:%f", angle);

        DrawRotaGraph(320, 240, exrate, angle, handle, 0);

        ScreenFlip();//裏画面を表画面にコピー
    }

    DxLib_End();
    return 0;
}
