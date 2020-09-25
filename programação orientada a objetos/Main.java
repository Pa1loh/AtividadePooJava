
public class Main {

	
	public static void main(String[] args) {
		
		// Cadastrando uma cidade e um ponto
		
		Prefeitura p1 = new Prefeitura(01, "Maringá", 01);     //Cidade
		p1.apresentarCidade();
		
		PontoEnergia pe1 = new PontoEnergia(01,"Centro","Centro de Maringá");
		pe1.apresentarPonto();
		
		
		

	}

}
