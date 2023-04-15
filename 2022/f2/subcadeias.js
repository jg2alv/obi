let N, C, grt = "";

scanf("%d", "N");
scanf("%s", "C");

for(let i = 0; i < N; i++) {
    for(let j = i; j < N; j++) {
        let sub = C.substring(i, j + 1);
        if(sub.length > grt.length && sub.split("").reverse().join("") === sub)
            grt = sub;
    }
}

printf("%d\n", grt);