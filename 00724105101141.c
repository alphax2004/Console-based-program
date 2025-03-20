#include<stdio.h>
#include<string.h>
int main()
{

    int choice;

    char product[3][100]={"Laptop","Smartphone","Headphones"};

    int price[3]={1000,700,150};

    int stock[3]={5,10,15};
    int cartquan[3]={0,0,0};

    printf("Online Shopping Cart System\n");

    printf("--------------------\n");

    do
    {
        
        printf("-------------------\n");

        printf("1.View Available Products\n");

        printf("2.Add Item to Cart\n");

        printf("3.View Cart\n");

        printf("4.Remove Item from cart\n");

        printf("5.Checkout\n");

        printf("6.Exit\n");

        printf("Enter your choice:");

        scanf("%d",&choice);

        printf("\n");

        switch(choice)
        {
            case 1:
                printf("Available Products:\n");

                printf("\n------------------\n");

                for(int i=0;i<3;i++)
                {
                    printf("[%d] %s-$%d (Stock: %d)\n",i+1,product[i],price[i],stock[i]); 
                }
                break;
            case 2:
            {
                int productno,quantity;

                printf("Enter product number to add:\n");
                scanf("%d",&productno);
                productno--;
                if(productno<0||productno>=3)
                {
                    printf("invalid");
                    break;
                }
                else
                {
                    printf("Enter quantity:\n");

                    scanf("%d",&quantity);
                    if(quantity<=0||quantity>stock[productno])
                    {
                    printf("invalid");
                    break;
                    }
                    else
                    {
                        stock[productno]-=quantity;
                        cartquan[productno]+=quantity;
                        printf("%s added to cart successfully!\n",product[productno]);

                    }
                }
            }

                break;
            case 3:
            {
                int total=0;
                printf("Your Shopping Cart:\n");

                printf("-------------------\n");
                for(int i=0;i<3;i++)
                {
                    if(cartquan[i]>0)
                    {
                        int itemtotal=cartquan[i]*price[i];

                        printf("%s - %d x $%d = $%d\n",product[i],cartquan[i],price[i],itemtotal);

                        total=total+itemtotal;
                    }
                }
                printf("Total:$%d\n",total);
            }
                break;
            
            case 4:
            {
                
                char name[30];
                 printf("Enter product name to remove: \n");
                 scanf("%s",name);
                
                for(int i=0;i<3;i++)
                {
                    if(strcmp(name,product[i])==0)
                    {
                        if(cartquan[i]>0)
                        {
                            stock[i]+=cartquan[i];
                            cartquan[i]=0;
                            printf("%s removed from cart!\n",product[i]);
                            break;

                        }
                    }
                }
                 
            }
                break;

            case 5:
            {
                int total=0;

                printf("Checkout Summary: \n");
                printf("\n---------------------\n");

                for(int i=0;i<3;i++)
            {
                if(cartquan[i]>0)
                {
                    int itemtotal=cartquan[i]*price[i];

                        printf("%s - %d x $%d = $%d\n",product[i],cartquan[i],price[i],itemtotal);

                        total=total+itemtotal;
                }

            }
            int discount=0;
            if(total>=2000)
            {
                discount=total*10/100;
            }

                printf("Total Cost: $%d\n",total);

                printf("Discount Applied: $%d\n",discount);

                printf("Final amount: $%d\n",total-discount);

                printf("Order Confirmed! Thank you for shopping with us.\n");

            }

                break;

            case 6:

                printf("Exiting the system........\n");

                printf("Thank you for using the Online Shopping Cart System!\n");

                break;

            default:
                
                printf("Invalid\n");
                break;        
        }
    } while (choice!=6);
    
}