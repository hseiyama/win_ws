#include <DxLib.h>
#include <stdio.h>

int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow )
{
    ChangeWindowMode( TRUE );//非全画面にセット
    SetGraphMode( 640 , 480 , 32 );//画面サイズ指定
    SetOutApplicationLogValidFlag( FALSE ) ;//Log.txtを生成しないように設定
    if(DxLib_Init() == 1){return -1;}//初期化に失敗時にエラーを吐かせて終了

    while( ProcessMessage()==0 )
    {
        ClearDrawScreen();//裏画面消す
        SetDrawScreen( DX_SCREEN_BACK ) ;//描画先を裏画面に

        DrawCircle(100, 100, 30, GetColor(255, 0, 0), 0);
        DrawCircle(300, 100, 30, GetColor(0, 255, 0), 1);
        DrawBox(50, 300, 100, 400, GetColor(0, 0, 255), 1);
        DrawLine(200, 300, 300, 400, GetColor(255, 255, 255), 1);

        ScreenFlip();//裏画面を表画面にコピー
    }

    DxLib_End();
    return 0;
}
