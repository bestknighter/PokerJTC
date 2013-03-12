/* Esta função recebe um ponteiro para o baralho, o valor da carta a ser
*  adicionada e seu respectivo naipe e então os adiciona no baralho.
*/
void addCarta(struct carta*, char, char);

/* Esta função retorna um endereço de um ponteiro para struct carta. A função
*  criará uma fila organizada com todas as 52 cartas normais de um baralho.
*/
struct carta** criaBaralho();
