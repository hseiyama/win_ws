#include <DxLib.h>
#include <stdio.h>

int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow )
{
    ChangeWindowMode( TRUE );//��S��ʂɃZ�b�g
    SetGraphMode( 640 , 480 , 32 );//��ʃT�C�Y�w��
    SetOutApplicationLogValidFlag( FALSE ) ;//Log.txt�𐶐����Ȃ��悤�ɐݒ�
    if(DxLib_Init() == 1){return -1;}//�������Ɏ��s���ɃG���[��f�����ďI��

    int hoge = 100;
    double piyo = 3.14;

    while( ProcessMessage()==0 )
    {
        ClearDrawScreen();//����ʏ���
        SetDrawScreen( DX_SCREEN_BACK ) ;//�`���𗠉�ʂ�

        DrawFormatString(100, 100, GetColor(255, 255, 255), "aaa %d %f", hoge, piyo);

        ScreenFlip();//����ʂ�\��ʂɃR�s�[
    }

    DxLib_End();
    return 0;
}
