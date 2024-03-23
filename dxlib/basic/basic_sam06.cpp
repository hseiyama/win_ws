#include <DxLib.h>
#include <stdio.h>

int mouseX = 0;//�}�E�X���W
int mouseY = 0;//�}�E�X���W

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

        GetMousePoint( &mouseX, &mouseY ); //�}�E�X���W�X�V

        //����ɕ����i�}�E�X�̍��W�j��`��
        DrawFormatString(20, 50, GetColor(255, 255, 255), "MX:%3d MY:%3d", mouseX, mouseY);

        ScreenFlip();//����ʂ�\��ʂɃR�s�[
    }

    DxLib_End();
    return 0;
}
