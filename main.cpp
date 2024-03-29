#include <string>
#include <iostream>
#include <iostream>
#include <unordered_map>

using namespace std;

void printstr(string str, int length) {
    for(int i=0; i < length ; ++i)
        printf("%c", str[i]);
}

int main() {
    int s;
    string n;
    int rows,cols;

    string template_row[10];
    string vertical_bar[10];
    string vertical_bar_l[10]; //left
    string vertical_bar_r[10]; //right
    string blank_row[10];

    for(int i=1 ; i <= 10 ; ++i) {
        int j=0;
        while( j < (i + 2)) {
            if( j == 0 || j == (i+1) ) {
                template_row[i-1] = template_row[i-1] + ' ';
                vertical_bar[i - 1] = vertical_bar[i - 1] + '|';
            } else {
                template_row[i-1]  = template_row[i-1] + '-';
                vertical_bar[i - 1] = vertical_bar[i - 1] + ' ';
            }

            if( j == 0 ) {
                vertical_bar_l[i - 1] = vertical_bar_l[i - 1] + '|';
                vertical_bar_r[i - 1] = vertical_bar_r[i - 1] + ' ';
            } else if (j == (i+1) ) {
                vertical_bar_l[i - 1] = vertical_bar_l[i - 1] + ' ';
                vertical_bar_r[i - 1] = vertical_bar_r[i - 1] + '|';
            } else {
                vertical_bar_l[i - 1] = vertical_bar_l[i - 1] + ' ';
                vertical_bar_r[i - 1] = vertical_bar_r[i - 1] + ' ';
            }

            blank_row[i-1] = blank_row[i-1] + ' ';
            ++j;
        }
    }

    while(cin>>s>>n) {
        auto res = s + stoi(n);

        if (!res)
            break;

        rows = 2 * s + 3;
        auto mid_row = s + 1;
        cols = s + 2;
        auto num = n;

        for(int i=0 ; i < rows ; ++i) {
            for(auto it=num.begin() ; it != num.end(); ++it) {

                if( i == 0 ) {
                    switch(*it) {
                        case '1':
                            printstr( blank_row[s-1], cols); break;
                        case '4':
                            printstr( blank_row[s-1], cols); break;
                        default:
                            printstr(template_row[s-1], cols);
                    }

                    if (it != num.end()- 1)
                        printf(" ");

                } else if( i == mid_row) {
                    switch(*it) {
                        case '0':
                            printstr(blank_row[s-1], cols ); break;
                        case '1':
                            printstr( blank_row[s-1], cols ); break;
                        case '7':
                            printstr( blank_row[s-1], cols ); break;
                        default:
                            printstr(template_row[s-1], cols);
                    }
                    if (it != num.end() - 1)
                        printf(" ");

                } else if ( i == rows - 1) {
                    switch(*it) {
                        case '1':
                            printstr( blank_row[s-1], cols ); break;
                        case '4':
                            printstr(blank_row[s-1], cols ); break;
                        case '7':
                            printstr(blank_row[s-1], cols ); break;
                        default:
                            printstr(template_row[s-1], cols);
                    }

                    if (it != num.end()- 1)
                        printf(" ");
                } else {
                    switch(*it) {
                        case '1':
                            printstr(vertical_bar_r[s - 1], cols ); break;
                        case '2':
                            if ( i < mid_row)
                                printstr(vertical_bar_r[s - 1], cols);
                            else
                                printstr( vertical_bar_l[s - 1], cols  );
                            break;
                        case '3':
                            printf("%s", vertical_bar_r[s - 1].c_str() ); break;
                        case '4':
                            if ( i < mid_row)
                                printstr(vertical_bar[s - 1], cols );
                            else
                                printstr(vertical_bar_r[s - 1], cols );
                            break;
                        case '5':
                            if ( i < mid_row)
                                printstr(vertical_bar_l[s - 1], cols );
                            else
                                printstr(vertical_bar_r[s - 1], cols );
                            break;
                        case '6':
                            if ( i < mid_row)
                                printstr( vertical_bar_l[s - 1], cols );
                            else
                                printstr( vertical_bar[s - 1], cols );
                            break;
                        case '7':
                            printstr(vertical_bar_r[s - 1], cols ); break;
                        case '9':
                            if ( i < mid_row)
                                printstr(vertical_bar[s - 1], cols );
                            else
                                printstr(vertical_bar_r[s - 1], cols );
                            break;
                        default:
                            printstr( vertical_bar[s - 1], cols );
                    }

                    if (it != num.end()- 1)
                        printf(" ");
                }

            }
            printf("\n");
        }
        printf("\n");
    }
}