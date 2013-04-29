struct estatJogo{
    int nJogadoresTotal;
    int nJogadoresAtivo;
    int smallBlind;
    int bigBlind;
    int apostaAtual;
    int valorDaMesa;
    int rodadaAtual;
    struct jogador **jogadores;
    struct carta **maoMesa;
}Stats;
