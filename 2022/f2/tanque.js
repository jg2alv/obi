let C, D, T, fill;

scanf("%d", "C");
scanf("%d", "D");
scanf("%d", "T");

fill = (D/C - T).toFixed(1);

if(fill > 0)
    printf("%d\n", fill);
else
    printf("0.0\n",);
