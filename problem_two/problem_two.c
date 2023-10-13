#include <stdio.h>

int main() {
    int myNum = 100;
    char array[100][6];
    int pass_code = 1;

    while (pass_code == 1)
    {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter NFL score: ");
        scanf("%d", &myNum);

        if (myNum <= 1) {
            pass_code = 0;
            return 0;
        }

        for (int a = 0; a < 100; a++)
        {
            for (int b = 0; b < 6; b++)
                {
                    array[a][b] = 0;
                }
            
        }

        int combinations = 0;

        printf("\n");
        
        for (int safeties = 0; safeties * 2 <= myNum; safeties++) {
            for (int field_goals = 0; field_goals * 3 <= myNum; field_goals++) {
                for (int touch_downs = 0; touch_downs * 6 <= myNum; touch_downs++) {
                    for (int touch_down_fgs = 0; touch_down_fgs * 7 <= myNum; touch_down_fgs++) {
                        for (int touch_down_twos = 0; touch_down_twos * 8 <= myNum; touch_down_twos++) {
                            int total = safeties * 2 + field_goals * 3 + touch_downs * 6 + touch_down_fgs * 7 + touch_down_twos * 8;
                            
                            if (total == myNum) {
                                array[combinations][0] = touch_down_twos;
                                array[combinations][1] = touch_down_fgs;
                                array[combinations][2] = touch_downs;
                                array[combinations][3] = field_goals;
                                array[combinations][4] = safeties;
                                combinations += 1;
                            }
                        }
                    }
                }
            }
        }

        printf("\n");
        printf("Possible combinations of scoring plays:\n");
        for (int i = 0; i < combinations; i++) {
            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", array[i][0], array[i][1], array[i][2], array[i][3], array[i][4]);
        }
    }

    return 0;
}
