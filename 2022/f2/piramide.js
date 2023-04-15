let N, str = "";
scanf("%d", "N");

for(let i = 0; i < N; i++) {
    for(let j = 0; j < N; j++) {
        for(let k = 0; k < N; k++) {
            let last = N - k;
            if(i === k || j === k || i === last || j === last) {
                str += `${k + 1} `;
                break;
            }
        }
    }

    str += "\n";
}

printf(str.trimEnd());