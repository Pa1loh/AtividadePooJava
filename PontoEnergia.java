
public class PontoEnergia implements Menu {
	
	private int idPonto;
	private String localização;
	private String descricao;
	
	
	public int getIdPonto() {
		return idPonto;
	}
	public void setIdPonto(int idPonto) {
		this.idPonto = idPonto;
	}
	public String getLocalização() {
		return localização;
	}
	public void setLocalização(String localização) {
		this.localização = localização;
	}
	public String getDescricao() {
		return descricao;
	}
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	
	
	
	public PontoEnergia(int idPonto, String localização, String descricao) {
		super();
		this.idPonto = idPonto;
		this.localização = localização;
		this.descricao = descricao;
	}
	@Override
	public void cadastrarPonto() {
		
		
	}
	@Override
	public void apresentarPonto() {
		System.out.println("------------Ponto------------");
		System.out.println("Id do Ponto: " + this.getIdPonto());
		System.out.println("Localização: " + this.getLocalização());
		
		
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
