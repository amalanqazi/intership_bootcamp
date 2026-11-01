#include<stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    //القيم التي عتتغير اذا وجد عشان نتحقق من كلمة المرور 
    int min_length = 10;
    int has_number = 0;
    int has_special = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int is_length_ok = 0;


    char password[25];
    printf("enter your password should be contain at least 1 number ,1 special character and character length of at least: %d\n", min_length);
    fgets(password, sizeof(password), stdin);
    // تتحقق من حذف الفراغ الي يضيفه fgets ويقدم النهاية 0 عشان يطلع الطول الحقيقي 
    password[strcspn(password, "\n")] = '\0';
    for (size_t i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            has_number = 1;
        }
        else if (islower(password[i]))
        {
            has_lowercase = 1;
        }
        else if (isupper(password[i]))
        {
            has_uppercase = 1;
        }
        else {
            has_special = 1;
        }

      
    }
    /*
    if (strlen(password) >= min_length && has_number && has_special && has_uppercase)
    {
        printf("your password is valid ");
        //تحقق من لطول 
        printf("size of password is %zu\n", strlen(password));
        return 0;
    }
    printf("your password is invalid check and submit again");
    //تحقق من الطول احتياط 
    printf("size of password is %zu\n", strlen(password));
    */

    if(strlen(password) >= min_length) is_length_ok = 1;

    int score = has_uppercase + has_lowercase + has_number + has_special + is_length_ok;

    if(!is_length_ok){
        printf("Your Password is Weak");
    } else if (score >= 4){
        printf("Your Password is Strong");
    } else {
        printf("Your Password is Medium");
    }
   
    return 0;
}
