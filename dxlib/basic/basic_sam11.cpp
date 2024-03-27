#include <DxLib.h>
#include <stdio.h>

int mouseX = 0;//�}�E�X���W
int mouseY = 0;//�}�E�X���W

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
    SetGraphMode(640, 480, 32);//��ʃT�C�Y�w��
    SetOutApplicationLogValidFlag(FALSE);//Log.txt�𐶐����Ȃ��悤�ɐݒ�
    if (DxLib_Init() == 1){ return -1; }//�������Ɏ��s���ɃG���[��f�����ďI��

    int handle = LoadGraph("sample.png");

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();//����ʏ���
        SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�

        GetMousePoint(&mouseX, &mouseY); //�}�E�X���W�X�V

        double exrate = mouseX / 100.0;
        double angle = mouseY / 100.0;

        DrawFormatString(20, 20, GetColor(255, 255, 255), "mouseX:%d", mouseX);
        DrawFormatString(20, 40, GetColor(255, 255, 255), "mouseY:%d", mouseY);
        DrawFormatString(20, 60, GetColor(255, 255, 255), "exrate:%f", exrate);
        DrawFormatString(20, 80, GetColor(255, 255, 255), "angle:%f", angle);

        DrawRotaGraph(320, 240, exrate, angle, handle, 0);

        ScreenFlip();//����ʂ�\��ʂɃR�s�[
    }

    DxLib_End();
    return 0;
}
