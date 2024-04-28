#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int ROW = 25;
const int COL = 25;

bool searchWord(char grid[ROW][COL], string word) {
    int len = word.length();

  if (len > ROW && len > COL) {
        return false;
    }

    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (tolower(grid[row][col]) == tolower(word[0])) {
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int k, rd = row + x, cd = col + y;
                        for (k = 1; k < len; k++) {
                            if (rd >= ROW || rd < 0 || cd >= COL || cd < 0)
                                break;
                            if (tolower(grid[rd][cd]) != tolower(word[k]))
                                break;
                            rd += x, cd += y;
                        }
                        if (k == len)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    char grid[ROW][COL] = { 
        "AAFLKHPFSSUFICICLESGNNH",
        "SFVREOMRWLRTTSXOQQNAOAO",
        "QEIAIFXAEIRFVFYSXIMINJI",
        "WSTRLGOCAPBIAFIWIWTUACM",
        "FEYAEAISTPCRLUJKOAKCERS",
        "RVDAKPNDEEHDEMSNCKKFOAH",
        "MRNEDSLCRRIWNRSAAFITMMI",
        "YAAECIEAHYMOTAVHRSSTISB",
        "RJSEWELCCENNIETOHWSGLSE",
        "ATANYYMOIEESNESIOIRELTR",
        "UTENEWEBHMYBETNNRAIEBEN",
        "RCLKUTEAEQJLSGSHTGDSKOA",
        "BHOICATNRRSDDECEHOOLGIT",
        "ENSLUARIRSETALOCOHCTOHE",
        "FZFUDQJYMADOYIWYGLOVESU",
        "TEKALFWONSNAEBMIEJTZNTG",
        "ESWPOSJXEUTUYOZUWAKEZHM",
        "KZUHBPEZEERFLMSNOWBALLH",
        "NSNOWBOARDYTVWYCLEVOHSA",
        "ACOCRQLGZIYCHODRAZZILBI",
        "LBVKKWANZAAQINWOLPWONSL",
        "BFREEZINGRAINSLILGTMELT",
        "HQPYLWHFMNFFUFPSWXNUMMV"};
    int n;
    cout << "Masukkan jumlah kata yang ingin dicari: ";
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cout << "Masukkan kata ke-" << i+1 << ": ";
        cin >> words[i];
    }

    for (const auto &word : words) {
        if (searchWord(grid, word))
            cout << "Kata '" << word << "' ada dalam array.\n";
        else
            cout << "Kata '" << word << "' tidak ada dalam array.\n";
    }

    return 0;
}
