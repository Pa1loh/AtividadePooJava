
public class Prefeitura implements Menu {

	private int idCidade;
	private String nomeCidade;
	private int pontosCadastrados; //numeros de pontos cadastrados na cidade
	
	
	
	public Prefeitura(int idCidade, String nomeCidade, int pontosCadastrados) {
		super();
		this.idCidade = idCidade;
		this.nomeCidade = nomeCidade;
		this.pontosCadastrados = pontosCadastrados;
	}
	
	public int getIdCidade() {
		return idCidade;
	}
	public void setIdCidade(int idCidade) {
		this.idCidade = idCidade;
	}
	public String getNomeCidade() {
		return nomeCidade;
	}
	public void setNomeCidade(String nomeCidade) {
		this.nomeCidade = nomeCidade;
	}
	public int getPontosCadastrados() {
		return pontosCadastrados;
	}
	public void setPontosCadastrados(int pontosCadastrados) {
		this.pontosCadastrados = pontosCadastrados;
	}
	
	
	@Override
	public void cadastrarCidade() {      //Função para cadastro de cidade
		
	
		
	}
	@Override
	public void apresentarCidade() {
		System.out.println("------------Cidade------------");
		System.out.println("Id da Cidade: " + this.getIdCidade());
		System.out.println("Nome da Cidade: " + this.getNomeCidade());
		System.out.println("Numero de Pontos cadastrados : " + this.getPontosCadastrados());
		
		
		
	}
	@Override
	public void cadastrarPonto() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void apresentarPonto() {
		// TODO Auto-generated method stub
		
	}
	
	
	
	
}
