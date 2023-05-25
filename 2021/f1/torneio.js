let cont = 0, jogo;

for (let i = 0; i < 6; i++) {
    scanf("%s", "jogo")
    if (jogo === 'V')
        cont++
}

if (cont == 5 || cont == 6)
    printf("1\n")
else if (cont == 3 || cont == 4)
    printf("2\n")
else if (cont == 1 || cont == 2)
    printf("3\n")
else
    printf("-1\n")