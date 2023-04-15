let d, a, n, total;
scanf("%d", "d");
scanf("%d", "a");
scanf("%d", "n");

if(n < 16)
    total = (32 - n) * (d + (n - 1) * a);
else
    total = (32 - n) * (d + 14 * a);

printf("%d\n", total)