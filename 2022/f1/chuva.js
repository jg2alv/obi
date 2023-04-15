let N, S, count = 0, med = [];
scanf("%d", "N");
scanf("%d", "S");

function sum(st, en, arr) {
    let s = 0;
    for(let i = st; i <= en; i++)
        s += arr[i];

    return s;
}

for(let i = 0; i < N; i++) {
    scanf("%d", med[i]);
}

for(let i = 0; i < N; i++) {
    for(let j = i; j < N; j++) {
        let s = sum(i, j, med);
        if(s === S)
            count++;
    }
}

printf("%d\n", count);