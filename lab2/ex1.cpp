//menu driven program to find area of square,rectangle,cube,cuboid using classes

#include <stdio.h>
class shape
{
    private:
        int len,bre,hei;
    public:
        shape()
        {
            len=bre=hei=1;
        }
        void set_l(int l)
        {
            len=l;
        }
        void set_b(int b)
        {
            bre=b;
        }
        void set_h(int h)
        {
            hei=h;
        }
        int square()
        {
            return len*len;
        }
        int rectangle()
        {
            return len*bre;
        }
        int cube()
        {
            return 6*len*len;
        }
        int cuboid()
        {
            return 2*(len*bre+bre*hei+len*hei);
        }
};
int main()
{
    shape obj1;
    int ch,len,bre,hei;
    do
    {
        printf("\tMENU\n1.Square\n2.Cube\n3.Rectangle\n4.Cuboid\n5.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter length:");
            scanf("%d",&len);
            if (len<0)
            {
                printf("Invalid input for length\n");
                break;
            }
            obj1.set_l(len);
            printf("Area of square is %d\n",obj1.square());
            break;
        case 2:
            printf("Enter length:");
            scanf("%d",&len);
            if (len<0)
            {
                printf("Invalid input for length\n");
                break;
            }
            obj1.set_l(len);
            printf("Area of cube is %d\n",obj1.cube());
            break;
        case 3:
            printf("Enter length:");
            scanf("%d",&len);
            if (len<0)
            {
                printf("Invalid input for length\n");
                break;
            }
            obj1.set_l(len);
            printf("Enter breadth:");
            scanf("%d",&bre);
            if (bre<0)
            {
                printf("Invalid input for breadth\n");
                break;
            }
            obj1.set_b(bre);
            printf("Area of rectangle is %d\n",obj1.rectangle());
            break;
        case 4:
            printf("Enter length:");
            scanf("%d",&len);
            if (len<0)
            {
                printf("Invalid input for length\n");
                break;
            }
            obj1.set_l(len);
            printf("Enter breadth:");
            scanf("%d",&bre);
            if (bre<0)
            {
                printf("Invalid input for breadth\n");
                break;
            }
            obj1.set_b(bre);
            printf("Enter height:");
            scanf("%d",&hei);
            if (hei<0)
            {
                printf("Invalid input for height\n");
                break;
            }
            obj1.set_h(hei);
            printf("Area of cuboid is %d\n",obj1.cuboid());
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid input. Enter again.\n");
            break;
        }
    } while (ch!=5);
    return 0;
}
