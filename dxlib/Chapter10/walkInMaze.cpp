#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // �萔�̒�`
    const int WIDTH = 960, HEIGHT = 704; // �E�B���h�E�̕��ƍ����̃s�N�Z����

    SetWindowText("�L�����N�^�[�̈ړ��A�ǂƏ��̔���"); // �E�B���h�E�̃^�C�g��
    SetGraphMode(WIDTH, HEIGHT, 32); // �E�B���h�E�̑傫���ƃJ���[�r�b�g���̎w��
    ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ŋN��
    if (DxLib_Init() == -1) return -1; // ���C�u���������� �G���[���N������I��
    SetBackgroundColor(0, 0, 0); // �w�i�F�̎w��
    SetDrawScreen(DX_SCREEN_BACK); // �`��ʂ𗠉�ʂɂ���

    // ���H�̒�`
    const int MAZE_PIXEL = 64; // 1�}�X�����s�N�Z���Ƃ��邩
    const int MAZE_W = 15; // ���ɉ��}�X���邩
    const int MAZE_H = 11; // �c�ɉ��}�X���邩
    char maze[MAZE_H][MAZE_W] = { // ���H�̃f�[�^ 0�����A1����
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,0,0,1,1,0,1,1,0,1},
        {1,0,1,0,0,0,1,0,0,0,0,0,1,0,1},
        {1,0,1,0,1,0,1,0,1,1,1,0,1,0,1},
        {1,0,0,0,1,0,1,1,1,0,1,0,1,0,1},
        {1,0,1,1,1,0,1,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,1,1,1,0,1,0,1},
        {1,0,1,1,1,0,1,0,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    int chip[2] = { // �z��ɔw�i�̉摜��ǂݍ���
        LoadGraph("image/floor.png"),
        LoadGraph("image/wall.png")
    };
    int player[4] = { // �z��Ƀ��{�b�g�̉摜��ǂݍ���
        LoadGraph("image/robot_u.png"),
        LoadGraph("image/robot_d.png"),
        LoadGraph("image/robot_l.png"),
        LoadGraph("image/robot_r.png")
    };

    // �v���C���[�L�����ł��郍�{�b�g�p�̕ϐ�
    int playerX = 96; // x���W
    int playerY = 96; // y���W
    int playerD = 1; // ���� 0=��A1=���A2=���A3=�E

    while (1) // ���C�����[�v
    {
        ClearDrawScreen(); // ��ʂ��N���A����

        // ���H�̕`��
        int x, y, sx, sy;
        for (y = 0; y < MAZE_H; y++)
        {
            for (x = 0; x < MAZE_W; x++)
            {
                sx = x * MAZE_PIXEL; // �}�X��x���W
                sy = y * MAZE_PIXEL; // �}�X��y���W
                DrawGraph(sx, sy, chip[maze[y][x]], FALSE); // �w�i�̉摜��\��
            }
        }

        // �v���C���[�L�����𓮂�������
        int newX = playerX, newY = playerY; // �ړ���̍��W�i�������񌻍݂̍��W�����j
        if (CheckHitKey(KEY_INPUT_UP)) { newY = playerY - 2;  playerD = 0; } // ��L�[
        else if (CheckHitKey(KEY_INPUT_DOWN)) { newY = playerY + 2;  playerD = 1; } // ���L�[
        else if (CheckHitKey(KEY_INPUT_LEFT)) { newX = playerX - 2;  playerD = 2; } // ���L�[
        else if (CheckHitKey(KEY_INPUT_RIGHT)) { newX = playerX + 2;  playerD = 3; } // �E�L�[
        int mx1 = (newX - 20) / MAZE_PIXEL, my1 = (newY - 20) / MAZE_PIXEL; // ����p
        int mx2 = (newX + 19) / MAZE_PIXEL, my2 = (newY - 20) / MAZE_PIXEL; // �E��p
        int mx3 = (newX - 20) / MAZE_PIXEL, my3 = (newY + 19) / MAZE_PIXEL; // �����p
        int mx4 = (newX + 19) / MAZE_PIXEL, my4 = (newY + 19) / MAZE_PIXEL; // �E���p
        if (maze[my1][mx1] == 0 && maze[my2][mx2] == 0 && maze[my3][mx3] == 0 && maze[my4][mx4] == 0)
        {
            playerX = newX; // �� 4���Ƃ����Ȃ���W��ω�������
            playerY = newY; // ��
        }
        DrawGraph(playerX - 20, playerY - 20, player[playerD], TRUE); // ���{�b�g��\��

        ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f������
        WaitTimer(16); // ��莞�ԑ҂�
        if (ProcessMessage() == -1) break; // Windows��������󂯎��G���[���N������I��
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESC�L�[�������ꂽ��I��
    }

    DxLib_End(); // �c�w���C�u�����g�p�̏I������
    return 0; // �\�t�g�̏I��
}