#include<stdio.h>
#include<string.h>
#include<unistd.h>

int login_success(char *username, char *password)
{
	char user[64];
	int flag = 0;
	char pass[64];

	strcpy(user, username);
	strcpy(pass, password);

	//add login check here later

	return flag;
}

void print_users()
{
	char *arr[] = {"root", "foo", "bar", "john"};
	int num_users = 4;

	printf("*** Users ***\n");
	for (int i = 0; i < num_users; i++)
		printf("%s\n", arr[i]);
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		return -1;
	}

	char confirm;

	printf("Welcome to my impenetrable login screen!\nContinue? (y/n)\n");
	scanf("%c", &confirm);

	if (confirm != 'y' && confirm != 'Y')
		return -1;

	if(login_success(argv[1], argv[2]))
	{
		printf("Not supposed to work yet, finishing login function later\n");
		
		char *argvec[] = {"/bin/rbash",  0};
		char *envp[] = {0};

		execve(argvec[0], argvec, envp);
	}
	else
	{
		printf("HA! Bad login\n");
	}

	

}
