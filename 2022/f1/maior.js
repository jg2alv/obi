let N, M, S, I = -1;
scanf("%d", "N");
scanf("%d", "M");
scanf("%d", "S");

for(let i = N; i <= M; i++) {
    let strarr = i.toString().split("");
    let sum = 0;

    for(let j = 0; j < strarr.length; j++) {
        sum += Number(strarr[j]);
    }

    if(sum === S)
        I = i;
}

printf("%d\n", I);