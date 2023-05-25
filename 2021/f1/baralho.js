let chars, cartas = [], copas = 0, espadas = 0, ouros = 0, paus = 0, dups = {
    'C': false,
    'E': false,
    'U': false,
    'P': false
};

scanf("%s", "chars");

for (let i = 0; i < chars.length; i += 3) {
    let n = chars[i] + chars[i + 1];
    let naipe = chars[i + 2];
    let carta = n + naipe;

    if (naipe == 'C')
        copas++
    else if (naipe == 'E')
        espadas++
    else if (naipe == 'U')
        ouros++
    else if (naipe == 'P')
        paus++

    if(cartas.includes(carta)) {
        dups[naipe] = true;
    } else
        cartas.push(carta);
}

if(dups['C'])
    printf("erro\n");
else
    printf("%d\n", 13 - copas);

if (dups['E'])
    printf("erro\n")
else
    printf("%d\n", 13 - espadas);

if(dups['U'])
    printf("erro\n")
else
    printf("%d\n", 13 - ouros);

if(dups['P'])
    printf("erro\n")
else
    printf("%d\n", 13 - paus);
