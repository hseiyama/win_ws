#include <DxLib.h>
#include <stdio.h>

int WINAPI WinMain( HINSTANCE hInstance , HINSTANCE hPrevInstance , LPSTR lpCmdLine , int nCmdShow )
{
    ChangeWindowMode( TRUE );//��S��ʂɃZ�b�g
    SetGraphMode( 640 , 480 , 32 );//��ʃT�C�Y�w��
    SetOutApplicationLogValidFlag( FALSE ) ;//Log.txt�𐶐����Ȃ��悤�ɐݒ�
    if(DxLib_Init() == 1){return -1;}//�������Ɏ��s���ɃG���[��f�����ďI��

    while( ProcessMessage()==0 )
    {
        ClearDrawScreen();//����ʏ���
        SetDrawScreen( DX_SCREEN_BACK ) ;//�`���𗠉�ʂ�

        DrawCircle(100, 100, 30, GetColor(255, 0, 0), 0);
        DrawCircle(300, 100, 30, GetColor(0, 255, 0), 1);
        DrawBox(50, 300, 100, 400, GetColor(0, 0, 255), 1);
        DrawLine(200, 300, 300, 400, GetColor(255, 255, 255), 1);

        ScreenFlip();//����ʂ�\��ʂɃR�s�[
    }

    DxLib_End();
    return 0;
}
