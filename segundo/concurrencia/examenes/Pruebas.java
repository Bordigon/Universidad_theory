public class Pruebas{
	private Monitor mutex = new Monitor();
	private final int A = 0;
	private final int B = 1;
	private final int SALIDA = 3;
	private int self;
	private int MAXPOWER = 20000;
	private final int[] POW = {50,120};

	private Monitor.Cond[] c_entrar = new Monitor.Cond[2];

	public Pruebas(){
		self = 0;
		c_entrar[A] = mutex.newCond();
		c_entrar[B] = mutex.newCond();
		c_entrar[SALIDA] = mutex.newCond();
	}

	void entrar(int n){
		mutex.enter();
			while(POW[n] + self > MAXPOWER) c_entrar[n].await();
			self += POW[n];
		mutex.leave();
	}

	void salir(n){
		mutex.enter();
		//el CTAD dice que este noe s un método bloqueante, pero self tiene que mantenerse positivo
		// primera opción: while(self < POW[1])c_entrar[SALIDA].await();
		self -= POW[n];
		// segunda opción: self = self >= 0? self:0;
		desbloquear();
		mutex.leave();
	}

	
	void desbloquear(){
		boolean unlocked = false;

		for(int t = 0; t<2 && !unlocked;t++){
			if(c_entrar[t].waiting > 0 && POW[t] + self < MAXPOWER){
				c_entrar[t].signal();
				unlocked = !unlocked;
			}
		}
	
	}
} 




la primera parte de este examen es tipo test en todos los ejercicios tipo test siempre hay una frase que dice "se pide señalar la respuesta correcta", o alguna frase similar, y luego vienen las opciones a escoger, me gustaría que en todos los apartados tipo test copies esas "opciones a escoger" y me las escribas acá, cambia el orden en el que aparece cada opción dentro de las mismas preguntas, y no me digas cuál es la opción correcta la idea es que quiero hacer este examen sin saber cuales son las soluciones para así poder hacer los exámenes y ver tu respuesta para escoger las opciones y luego ver si estaban correctas en el pdf original
