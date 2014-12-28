#include "signveri.h"

using namespace std;

ofstream myfile_sv;


int* hash_verify=0;
int result;



void signverification()
{	
	int counter=0;
	hash_verify=new int[m];
	
	
	for(int i=0;i<m;i++)
	{	
		
		
		int* temp= new int [n+1];//memory allocated for temporary vector array;
		//memory allocated for hashvalue array;
		hash_verify[i]=0;

		for(int j=0;j<(n+1);j++)
		{	
			temp[j]=0;

			for(int k=j;k<n;k++)
				temp[j]=addTable(temp[j],mulTable(matrix_PK[i][j][k],signature[k]));
				
			temp[j]=addTable(temp[j],matrix_PK[i][j][n]);

		}
		
		for(int l=0;l<n;l++)
				hash_verify[i]=addTable(hash_verify[i],mulTable(signature[l],temp[l]));
		hash_verify[i]=addTable(hash_verify[i],temp[n]);

		if(hash_verify[i]==hashvalue[i])
			counter++;
	}
	
	if(counter==m)
		result=1;
	else
		result=0;
	
	
}

void print_signatureverification(int result)
{	
	myfile_sv.open("/home/ishtiaq/rainbow/rainbow_conventional_output/Signature Verification.txt");
	myfile_sv<<"\n\nSignature Verification\n\n";
	myfile_sv<<"Hash values generated by verification process\n\n";
	myfile_sv<<"Hashvalue= (";
	for(int i=0;i<m;i++)
	{	
		myfile_sv<<hash_verify[i];
		if(i!=(m-1))
			myfile_sv<<", ";
	}
	myfile_sv<<")"<<endl;

	if(result==1)
	{
		myfile_sv<<"\n\nHash values generated by verification process are equal to original Hashvalues\nSo Signature Authenticated";
	}
	else
	{
		myfile_sv<<"\n\nHash values generated by verification process are not equal to original Hashvalues\nSo Signature Authentication Failed";
	}
	myfile_sv.close();

}