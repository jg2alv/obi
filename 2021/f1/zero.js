let n, nums = [], num;

scanf("%d", "n");
for(let i = 0; i < n; i++) {
    scanf("%d", "num");
    if(num === 0)
        nums.pop();
    else
        nums.push(num);
}

let sum = nums.reduce((acc, curr) => curr + acc, 0);
printf("%d\n", sum);
