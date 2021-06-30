typedef struct proceso
{
	int pdi;
	char estatus;
	int llegada;
	int tim_uso;
} proceso;

proceso crear(int pdi, char estatus,int llegada, int uso){
	proceso pros;
	pros.estatus=estatus;
	pros.llegada=llegada;
	pros.pdi=pdi;
	pros.tim_uso=uso;
	return pros;
}
