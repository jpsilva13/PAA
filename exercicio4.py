import numpy as np

def calculaValores(somaValor,somaPeso):
    for item in itens:
        if(itensUtilizados[item[0]-1]==0):
            somaValor=somaValor + item[1];
            somaPeso=somaPeso + item[2];
    return somaValor,somaPeso;

def caixaValor():
    valorCaixa=0;
    bestValue=99;
    best=0;
    for item in itens:
        if (item[1]<bestValue) and (itensUtilizados[item[0]-1]==0) :
            best= item;
            bestValue=item[1];
    return best

def caixaPeso():
    pesoCaixa=0;
    bestValue=99;
    best=0;
    for item in itens:
        if (item[2]<bestValue) and (itensUtilizados[item[0]-1]==0) :
            best= item;
            bestValue=item[2];
    return best


itens= [(1,7,4), (2,2,3), (3,2,2), (4,1,2), (5,3,4), (6,4,1), (7,5,2), (8,3,3)];
limiteValor=10;
limitePeso=10;
somaValor=0;
somaPeso=0;
caixaN=0;
n=len(itens);
caixa=list();
caixas=list();
valorCaixa=0;
pesoCaixa=0;

itensUtilizados=np.zeros((n), dtype=int)
i=0;

while(i<n):
    somaValor,somaPeso=calculaValores(somaValor,somaPeso);
    input()
    if (somaValor<somaPeso):
        print("Caixa valor gerada:")
        while ( valorCaixa<=limiteValor) and ( i<n):
            best=caixaValor();
            valorCaixa=valorCaixa+int(best[1]);
            if(valorCaixa<=limiteValor):
                print("Item inserido:",best)
                caixa.append(best);
                itensUtilizados[best[0]-1]=1;

                i=i+1;
    else:
        print("Caixa Peso gerada:")
        while (pesoCaixa<=limitePeso) and (i<n):
            best=caixaPeso();
            pesoCaixa=pesoCaixa+int(best[2]);
            if(pesoCaixa<=limitePeso):
                print("Item inserido:",best)
                caixa.append(best);
                itensUtilizados[best[0]-1]=1;
                i=i+1;
    caixaAdd=caixa.copy();
    caixas.append(caixaAdd);
    caixa.clear();
    somaValor=0;
    somaPeso=0;
    valorCaixa=0;
    pesoCaixa=0;

print("As caixas geradas foram:",caixas);
