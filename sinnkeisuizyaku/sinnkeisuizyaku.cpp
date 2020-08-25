#include <iostream>
using namespace std;
#include<ctime>

int main()
{
    srand(time(NULL));

    //トランプを模した配列を用意する
    int card[4][13];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            card[i][j] = j + 1;
        }
    }

    
    //フィールドに並べるカードの中身を入れる配列
    int field[4][13] = {0};

    //選んだものがすでにめくられているものかをチェックする
    int pickCheck[4][13] = { 0 };

    //画面にカード一覧を表示する
    //二次元配列で表示できなかったためすべて書いた
    char showfield[4][13] = {
        {'?','?','?','?','?','?','?','?','?','?','?','?','?'},
        {'?','?','?','?','?','?','?','?','?','?','?','?','?'},
        {'?','?','?','?','?','?','?','?','?','?','?','?','?'},
        {'?','?','?','?','?','?','?','?','?','?','?','?','?'},
    };
    

    int mark = 0;
    int num = 0;
    int line1 = 0;
    int row1 = 0;
    int line2 = 0;
    int row2 = 0;
    int firstpick = 0;
    int secondpick = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13;) {
            mark = rand() % 4;
            num = rand() % 13;
            if (field[mark][num] < 1) {
                field[mark][num] = card[i][j];
                j++;
            }       
        }

    }


    while (true)
    {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 13; ++j) {
                cout << showfield[i][j] << " ";
            }
            cout << endl;
        }

        while (true) {
            cout << "一枚目のめくる場所を選んでください" << endl;
            cout << "何行目（縦）？" << endl;
            cin >> line1;
            cout << "何列目（横）？" << endl;
            cin >> row1;

            if (pickCheck[line1-1][row1-1] == 1) {
                cout << "すでにめくられたカードです" << endl;
                cout << "もう一度選んでください" << endl;
            }
            else {
                break;
            }
        }
        
        cout << "一枚目は" << field[line1 - 1][row1 - 1] << "でした" << endl;
        
        firstpick = field[line1 - 1][row1 - 1];

        while (true) {
            cout << "二枚目のめくる場所を選んでください" << endl;
            cout << "何行目？（縦）" << endl;
            cin >> line2;
            cout << "何列目？（横）" << endl;
            cin >> row2;

            if (pickCheck[line2-1][row2-1] == 1) {
                cout << "すでにめくられたカードです" << endl;
                cout << "もう一度選んでください" << endl;
            }
            else
            {
                break;
            }
        }
        
        cout << "二枚目は" << field[line2 - 1][row2 - 1] << "でした" << endl;

        secondpick = field[line2 - 1][row2 - 1];

        if (firstpick == secondpick) {
            cout << "一致しました！" << endl;
            showfield[line1-1][row1-1] = firstpick;
            showfield[line2-1][row2-1] = secondpick;

            pickCheck[line1-1][row1-1] = 1;
            pickCheck[line2-1][row2-1] = 1;
        }
        else
        {
            cout << "一致しませんでした" << endl;
        }

    }

}

