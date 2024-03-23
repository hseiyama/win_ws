#include <DxLib.h>
#include <stdio.h>

//
//ここで変数を用意
//

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

    ChangeWindowMode(TRUE);//非全画面にセット
    SetGraphMode(640, 480, 32);//画面サイズ指定
    SetOutApplicationLogValidFlag(FALSE);//Log.txtを生成しないように設定
    if (DxLib_Init() == 1){ return -1; }//初期化に失敗時にエラーを吐かせて終了

    //
    //ここで画像・音を読み込み
    //

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();//裏画面消す
        SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に

        //
        //ここに毎フレーム呼ぶ処理を書く
        //

        ScreenFlip();//裏画面を表画面にコピー
    }

    DxLib_End();
    return 0;
}
