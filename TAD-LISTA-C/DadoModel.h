int gravar_lista(tipo_lista la);
int carregar_lista(tipo_lista *la);

//le do model pro controller pra ler
int ler_lista(tipo_lista *la){
  int pos = 0;
  FILE *arquivo;
  dado pessoa;
  arquivo = fopen("dados.dat", "rb")
  if(arquivo != NULL){
    while(fread(&pessoa, sizeof(dado),1,arquivo)){
      push(la, ++pos, pessoa);
    }  
    return 1;
  }
  return 0;
  
  fclose(arquivo);
}

//le do controller pro model pra gravar
int gravar_lista(tipo_lista la) {
   FILE *arquivo;
   dado pessoa;
   arquivo = fopen("dados.dat","wb");
   for (int i=1; i<=tamanho(la);i++) {
       get(la,i,&pessoa); //le a lista
       fwrite(&pessoa, sizeof(dado),1,arquivo); //grava o lido    
   }
   fclose(arquivo);
}