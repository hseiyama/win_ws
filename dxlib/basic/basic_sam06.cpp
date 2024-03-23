#include <DxLib.h>
#include <stdio.h>

int mouseX = 0;//マウス座標
int mouseY = 0;//マウス座標

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

        GetMousePoint( &mouseX, &mouseY ); //マウス座標更新

        //左上に文字（マウスの座標）を描画
        DrawFormatString(20, 50, GetColor(255, 255, 255), "MX:%3d MY:%3d", mouseX, mouseY);

        ScreenFlip();//裏画面を表画面にコピー
    }

    DxLib_End();
    return 0;
}
