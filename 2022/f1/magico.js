let N, R, C, x, parcsum = 0, sum1 = 0, sum2 = 0, sumres = 0, square = [];
scanf("%d", "N");

for(let row = 0; row < N; row++) {
    square[row] = [];
    
    for(let col = 0; col < N; col++) {
       scanf("%d", "square[row][col]");
       if(square[row][col] === 0) {
            R = row;
            C = col;
       } 
    }
}

// computing the first sum for comparison
for(let row = 0; row < N; row++) {
    sum1 += square[row][0];
}

// computing a second sum for comparison
for(let row = 0; row < N; row++) {
    sum2 += square[row][N - 1];
}

// geting the parcial sum in row and col where X is
for(let row = 0; row < N; row++) {
    parcsum += square[row][C];
}

// getting the total sum since X will not affect both sums
sumres = Math.max(sum1, sum2);
x = sumres - parcsum;

printf("%d\n", x);
printf("%d\n", R + 1);
printf("%d\n", C + 1);