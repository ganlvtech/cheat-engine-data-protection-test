#include <stdio.h>

// clear printf stack
#define PRINT_HP_CLEAR_STACK(hp) \
    printf("%d", (hp));          \
    clear_stack(0, 0);

// hide constant 100, ((hp >= 128) || (hp >= 64) && (hp % 64) > (100 % 64))
#define BIGGER_THAN_100(hp) (((hp) >> 7) || ((hp) >> 6) && (((hp)&0x3F) > (100 & 0x3F)))

#define WAIT_ENTER_OR_RETURN_0 \
    if ('\n' != getchar())     \
    {                          \
        return 0;              \
    }

int clear_stack(int a, int b)
{
    return a ^ b;
}

int normal_integer()
{
    printf("提示：4 字节整数。\n");
    for (int hp = 100; hp > 0; hp--)
    {
        printf("%d", hp);
        if (hp > 100)
        {
            return 1;
        }
        WAIT_ENTER_OR_RETURN_0;
    }
    return 0;
}

int float_conversion()
{
    printf("提示：单精度浮点型。\n");
    for (float hp = 100; hp > 0; hp -= 1)
    {
        int hp2 = (int)hp;
        printf("%d", hp2);
        if (hp2 > 100)
        {
            return 1;
        }
        hp2 = 0;
        WAIT_ENTER_OR_RETURN_0;
    }
    return 0;
}

int string_conversion()
{
    printf("提示：字符串类型。\n");
    char s[4] = "100";
    for (;;)
    {
        int hp2;
        hp2 = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            hp2 *= 10;
            hp2 += s[i] - '0';
        }
        PRINT_HP_CLEAR_STACK(hp2);
        if (BIGGER_THAN_100(hp2))
        {
            return 1;
        }
        hp2 = 0;
        WAIT_ENTER_OR_RETURN_0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            hp2 *= 10;
            hp2 += s[i] - '0';
        }
        hp2--;
        if (hp2 <= 0)
        {
            return 0;
        }
        int len = 0;
        for (int i = 0; hp2 > 0; i++)
        {
            s[i] = hp2 % 10 + '0';
            hp2 /= 10;
            len++;
        }
        s[len] = '\0';
        for (int i = 0, j = len - 1; i < j; i++, j--)
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
    return 0;
}

int multiply_transformation()
{
    printf("提示：数据都是 10 的倍数。\n");
    for (int hp = 10; hp > 0; hp--)
    {
        int hp2 = hp * 10;
        PRINT_HP_CLEAR_STACK(hp2);
        if (BIGGER_THAN_100(hp2))
        {
            return 1;
        }
        hp2 = 0;
        WAIT_ENTER_OR_RETURN_0;
    }
    return 0;
}

int negative_transformation()
{
    printf("提示：一种很简单的加密，搜索改变了的数值，显示为有符号整数。\n");
    for (int hp = -100; hp < 0; hp++)
    {
        int hp2 = -hp;
        PRINT_HP_CLEAR_STACK(hp2);
        if (BIGGER_THAN_100(hp2))
        {
            return 1;
        }
        hp2 = 0;
        WAIT_ENTER_OR_RETURN_0;
    }
    return 0;
}

int xor_transformation()
{
    printf("提示：异或加密，搜索改变了的数值，分析反汇编程序，代码注入。\n");
    for (int hp = 100 ^ 0xFFFF5A5A;;)
    {
        int hp2;
        hp2 = hp ^ 0xFFFF5A5A;
        PRINT_HP_CLEAR_STACK(hp2);
        if (BIGGER_THAN_100(hp2))
        {
            return 1;
        }
        hp2 = 0;
        WAIT_ENTER_OR_RETURN_0;
        hp2 = hp ^ 0xFFFF5A5A;
        hp2--;
        if (hp2 <= 0)
        {
            return 0;
        }
        hp = hp2 ^ 0xFFFF5A5A;
    }
    return 0;
}

int bits_array()
{
    printf("提示：7 个 4 字节分开表示每个二进制位。\n");
    int hp[7];
    hp[6] = (100 >> 6) & 1;
    hp[5] = (100 >> 5) & 1;
    hp[4] = (100 >> 4) & 1;
    hp[3] = (100 >> 3) & 1;
    hp[2] = (100 >> 2) & 1;
    hp[1] = (100 >> 1) & 1;
    hp[0] = (100 >> 0) & 1;
    for (;;)
    {
        int hp2;
        hp2 = 0;
        hp2 |= hp[6] << 6;
        hp2 |= hp[5] << 5;
        hp2 |= hp[4] << 4;
        hp2 |= hp[3] << 3;
        hp2 |= hp[2] << 2;
        hp2 |= hp[1] << 1;
        hp2 |= hp[0] << 0;
        PRINT_HP_CLEAR_STACK(hp2);
        if (BIGGER_THAN_100(hp2))
        {
            return 1;
        }
        hp2 = 0;
        WAIT_ENTER_OR_RETURN_0;
        hp2 |= hp[6] << 6;
        hp2 |= hp[5] << 5;
        hp2 |= hp[4] << 4;
        hp2 |= hp[3] << 3;
        hp2 |= hp[2] << 2;
        hp2 |= hp[1] << 1;
        hp2 |= hp[0] << 0;
        hp2--;
        if (hp2 <= 0)
        {
            return 0;
        }
        hp[6] = (hp2 >> 6) & 1;
        hp[5] = (hp2 >> 5) & 1;
        hp[4] = (hp2 >> 4) & 1;
        hp[3] = (hp2 >> 3) & 1;
        hp[2] = (hp2 >> 2) & 1;
        hp[1] = (hp2 >> 1) & 1;
        hp[0] = (hp2 >> 0) & 1;
    }
    return 0;
}

int gray_code_array()
{
    printf("提示：7 个 4 字节，格雷码。\n");
    int hp[7];
    hp[6] = ((100 >> 7) & 1) ^ ((100 >> 6) & 1);
    hp[5] = ((100 >> 6) & 1) ^ ((100 >> 5) & 1);
    hp[4] = ((100 >> 5) & 1) ^ ((100 >> 4) & 1);
    hp[3] = ((100 >> 4) & 1) ^ ((100 >> 3) & 1);
    hp[2] = ((100 >> 3) & 1) ^ ((100 >> 2) & 1);
    hp[1] = ((100 >> 2) & 1) ^ ((100 >> 1) & 1);
    hp[0] = ((100 >> 1) & 1) ^ ((100 >> 0) & 1);
    for (;;)
    {
        int tmp;
        int hp2;
        tmp = 0;
        hp2 = 0;
        tmp = hp[6] ^ tmp;
        hp2 |= tmp << 6;
        tmp = hp[5] ^ tmp;
        hp2 |= tmp << 5;
        tmp = hp[4] ^ tmp;
        hp2 |= tmp << 4;
        tmp = hp[3] ^ tmp;
        hp2 |= tmp << 3;
        tmp = hp[2] ^ tmp;
        hp2 |= tmp << 2;
        tmp = hp[1] ^ tmp;
        hp2 |= tmp << 1;
        tmp = hp[0] ^ tmp;
        hp2 |= tmp;
        PRINT_HP_CLEAR_STACK(hp2);
        if (BIGGER_THAN_100(hp2))
        {
            return 1;
        }
        tmp = 0;
        hp2 = 0;
        WAIT_ENTER_OR_RETURN_0;
        tmp = hp[6] ^ tmp;
        hp2 |= tmp << 6;
        tmp = hp[5] ^ tmp;
        hp2 |= tmp << 5;
        tmp = hp[4] ^ tmp;
        hp2 |= tmp << 4;
        tmp = hp[3] ^ tmp;
        hp2 |= tmp << 3;
        tmp = hp[2] ^ tmp;
        hp2 |= tmp << 2;
        tmp = hp[1] ^ tmp;
        hp2 |= tmp << 1;
        tmp = hp[0] ^ tmp;
        hp2 |= tmp;
        hp2--;
        if (hp2 <= 0)
        {
            return 0;
        }
        hp[6] = ((hp2 >> 7) & 1) ^ ((hp2 >> 6) & 1);
        hp[5] = ((hp2 >> 6) & 1) ^ ((hp2 >> 5) & 1);
        hp[4] = ((hp2 >> 5) & 1) ^ ((hp2 >> 4) & 1);
        hp[3] = ((hp2 >> 4) & 1) ^ ((hp2 >> 3) & 1);
        hp[2] = ((hp2 >> 3) & 1) ^ ((hp2 >> 2) & 1);
        hp[1] = ((hp2 >> 2) & 1) ^ ((hp2 >> 1) & 1);
        hp[0] = ((hp2 >> 1) & 1) ^ ((hp2 >> 0) & 1);
    }
    return 0;
}

int array_index()
{
    printf("提示：128 个 4 字节，数组下标。\n");
    int hp[128];
    for (int i = 0; i < 128; i++)
    {
        if (BIGGER_THAN_100(i))
        {
            hp[i] = 0;
        }
        else
        {
            hp[i] = 1;
        }
    }
    for (;;)
    {
        int hp2 = 0;
        for (int i = 0; i < 128; i++)
        {
            if (hp[i] != 0)
            {
                hp2 = i;
            }
        }
        PRINT_HP_CLEAR_STACK(hp2);
        if (BIGGER_THAN_100(hp2))
        {
            return 1;
        }
        hp2 = 0;
        WAIT_ENTER_OR_RETURN_0;
        for (int i = 0; i < 128; i++)
        {
            if (hp[i] != 0)
            {
                hp2 = i;
            }
        }
        hp[hp2] = 0;
        hp2--;
        if (hp2 <= 0)
        {
            return 0;
        }
        hp[hp2] = 1;
    }
    return 0;
}

int main()
{
    for (;;)
    {
        printf("这个小游戏包含多个关卡，关卡的目标是一样的，但是血量数据的存储方式是不一样的：\n");
        printf("您现在的血量是 100，每按一次回车，血量都会减少，把血量改成大于 100 的数值则可过关。\n");
        printf("程序逻辑执行顺序：\n");
        printf("  1. 显示当前血量\n");
        printf("  2. 判断是否大于 100\n");
        printf("  3. 如果大于 100 则过关\n");
        printf("  4. 否则等待回车\n");
        printf("  5. 血量减少，并回到第 1 步。\n");
        printf("进入关卡后，输入 q 再按回车即可返回主菜单。\n");
        printf("\n");
        printf("请选择关卡（1 ~ 9）：");
        int n;
        scanf("%d", &n);
        getchar(); // eat the enter
        printf("\n");
        int (*func)();
        switch (n)
        {
        case 1:
            func = normal_integer;
            break;
        case 2:
            func = float_conversion;
            break;
        case 3:
            func = string_conversion;
            break;
        case 4:
            func = multiply_transformation;
            break;
        case 5:
            func = negative_transformation;
            break;
        case 6:
            func = xor_transformation;
            break;
        case 7:
            func = bits_array;
            break;
        case 8:
            func = gray_code_array;
            break;
        case 9:
            func = array_index;
            break;
        }
        printf("\n\n");
        if (func())
        {
            printf("您通过了第 %d 关。\n", n);
            if (n >= 7)
            {
                printf("这都让你做出来了？你好厉害啊！分享一下你的破解方法吧。\n", n);
            }
        }
        else
        {
            printf("你已经死了！\n");
        }
        printf("\n");
    }
    return 0;
}
