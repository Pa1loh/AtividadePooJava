
public class PontoEnergia implements Menu {
	
	private int idPonto;
	private String localiza��o;
	private String descricao;
	
	
	public int getIdPonto() {
		return idPonto;
	}
	public void setIdPonto(int idPonto) {
		this.idPonto = idPonto;
	}
	public String getLocaliza��o() {
		return localiza��o;
	}
	public void setLocaliza��o(String localiza��o) {
		this.localiza��o = localiza��o;
	}
	public String getDescricao() {
		return descricao;
	}
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	
	
	
	public PontoEnergia(int idPonto, String localiza��o, String descricao) {
		super();
		this.idPonto = idPonto;
		this.localiza��o = localiza��o;
		this.descricao = descricao;
	}
	@Override
	public void cadastrarPonto() {
		
		
	}
	@Override
	public void apresentarPonto() {
		System.out.println("------------Ponto------------");
		System.out.println("Id do Ponto: " + this.getIdPonto());
		System.out.println("Localiza��o: " + this.getLocaliza��o());
		
		
	}
	@Override
	public void cadastrarCidade() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void apresentarCidade() {
		// TODO Auto-generated method stub
		
	}
	
	
	

}
