/*
** main.c for main in /home/bruela/rendu/B4/B4-Assembleurx86-64/asmminilibc
**
** Made by bruela
** Login   <jonathan.bruel@epitech.eu>
**
** Started on  Mon Mar  6 21:10:41 2017 bruela
** Last update Thu Mar 30 15:47:39 2017 bruela
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t	strlen(const char *);
char	*strchr(const char *, int);
void	*memset(void *, int, size_t);
void	*memcpy(void *, const void *, size_t);
int	strcmp(const char *, const char *);
int	strncmp(const char *, const char *, size_t);
void	*memmove(void *, const void *, size_t);
char	*rindex(const char *, int);
int	strcasecmp(const char *, const char *);
size_t	strcspn(const char *, const char *);
char	*strstr(const char*, const char *);
char	*strpbrk(const char*, const char *);
size_t	strnlen(const char *, size_t);
char	*index(const char *, int);
char	*strchrnul(const char *, int);
char	*strrchr(const char *, int);
char	*strchrnul(const char *, int);

static void	teststrlen(void)
{
  printf("TEST 1 - strlen:\n");
  printf("TRY 1.1 : [4] [%ld]\n", strlen("toto"));
  printf("TRY 1.2 : [0] [%ld]\n", strlen(""));
  printf("TRY 1.3 : [11] [%ld]\n", strlen("tototodjkli"));
  printf("TRY 1.4 : [0] [%ld]\n", strlen(NULL));
}

static void	teststrchr(void)
{
  printf("TEST 2 - strchr:\n");
  printf("TRY 2.1 : [t] [%c]\n", *strchr("toto", 't'));
  printf("TRY 2.2 : [o] [%c]\n", *strchr("toto", 'o'));
  if (strchr("toto", 'k') == NULL)
    printf("TRY 2.3 : [NULL] [NULL]\n");
  else
    printf("TRY 2.3 : [NULL] [NOT NULL]\n");
  if (strchr("", 'k') == NULL)
    printf("TRY 2.4 : [NULL] [NULL]\n");
  else
    printf("TRY 2.4 : [NULL] [NOT NULL]\n");
  if (strchr(NULL, 'k') == NULL)
    printf("TRY 2.5 : [NULL] [NULL]\n");
  else
    printf("TRY 2.5 : [NULL] [NOT NULL]\n");
  printf("TRY 2.6 : [w] [%c]\n", *strchr("aaaaaaaaaaaaaaaaaaaaw", 'w'));
}

static void	testmemset(void)
{
  char		test[42];

  printf("TEST 3 - memset:\n");
  memset(test, '\0', 42);
  printf("TRY 3.1 : [1111] [%s]\n", (char *)memset(test, '1', 4));
  memset(test, '\0', 42);
  printf("TRY 3.2 : [k] [%s]\n", (char *)memset(test, 'k', 1));
  memset(test, '\0', 42);
  printf("TRY 3.3 : [] [%s]\n", (char *)memset(test, '1', 0));
  memset(test, '\0', 42);
  printf("TRY 3.4 : [ppppppppppp] [%s]\n", (char *)memset(test, 'p', 11));
  memset(test, '\0', 42);
  if (memset(NULL, 'p', 1) == NULL)
    printf("TRY 3.5 : [NULL] [NULL]\n");
  else
    printf("TRY 3.5 : [NULL] [NOT NULL]\n");
  memset(test, '\0', 42);
  memset(test, 'p', -1);
  printf("TRY 3.6 : [DON'T SEG FAULT]\n");
}

static void	testmemcpy(void)
{
  char		test[42];

  printf("TEST 4 - memcpy:\n");
  memset(test, '\0', 42);
  printf("TRY 4.1 : [1234] [%s]\n", (char *)memcpy(test, "1234", 4));
  memset(test, '\0', 42);
  printf("TRY 4.2 : [1234] [%s]\n", (char *)memcpy(test, "1234", 8));
  memset(test, '\0', 42);
  printf("TRY 4.3 : [12] [%s]\n", (char *)memcpy(test, "12", 2));
  memset(test, '\0', 42);
  printf("TRY 4.4 : [1234] [%s]\n", (char *)memcpy(test, "1234", 4));
  memset(test, '\0', 42);
  if (memcpy(NULL, "11", 2) == NULL)
    printf("TRY 4.5 : [NULL] [NULL]\n");
  else
    printf("TRY 4.5 : [NULL] [NOT NULL]\n");
  memset(test, '\0', 42);
  memcpy(test, NULL, 67);
  printf("TRY 4.6 : [DON'T SEG FAULT]\n");
  memset(test, '\0', 42);
  memcpy(test, "j", -1);
  printf("TRY 4.7 : [DON'T SEG FAULT]\n");
}

static void	teststrcmp(void)
{
  printf("TEST 5 - strcmp:\n");
  printf("TRY 5.1 : [%d] [%d]\n", strcmp("1234", "1234"), strcmp("1234", "1234"));
  printf("TRY 5.2 : [%d] [%d]\n", strcmp("12345", "1234"), strcmp("12345", "1234"));
  printf("TRY 5.3 : [%d] [%d]\n", strcmp("1234", "12345"), strcmp("1234", "12345"));
  printf("TRY 5.4 : [%d] [%d]\n", strcmp("12345", ""), strcmp("12345", ""));
  printf("TRY 5.5 : [%d] [%d]\n", strcmp("", "1"), strcmp("", "1"));
  printf("TRY 5.6 : [%d] [%d]\n", strcmp("abc", "abbcde"), strcmp("abc", "abbcde"));
  printf("TRY 5.7 : [%d] [%d]\n", strcmp("abc", "bbbbcde"), strcmp("abc", "bbbbcde"));
  strcmp(NULL, "jk");
  printf("TRY 5.8 : [DON'T SEG FAULT]\n");
  strcmp("hj", NULL);
  printf("TRY 5.9 : [DON'T SEG FAULT]\n");
}

static void	teststrncmp(void)
{
  printf("TEST 6 - strncmp:\n");
  printf("TRY 6.1 : [0] [%d]\n", strncmp("1234", "1234", 4));
  printf("TRY 6.2 : [0] [%d]\n", strncmp("1234", "1234", 1));
  printf("TRY 6.3 : [53] [%d]\n", strncmp("12345", "1234", 5));
  printf("TRY 6.4 : [0] [%d]\n", strncmp("12345", "1234", 4));
  printf("TRY 6.5 : [0] [%d]\n",strncmp("12345", "1234", 0));
  printf("TRY 6.6 : [-53] [%d]\n", strncmp("1234", "12345", 5));
  printf("TRY 6.7 : [49] [%d]\n", strncmp("12345", "", 5));
  printf("TRY 6.8 : [0] [%d]\n",  strncmp("12345", "", 0));
  printf("TRY 6.9 : [-49] [%d]\n", strncmp("", "1", 1));
  printf("TRY 6.10 : [1] [%d]\n", strncmp("abc", "abbcde", 6));
  printf("TRY 6.11 : [-1] [%d]\n", strncmp("abc", "bbbbcde", 7));
  printf("TRY 6.12 : [69] [%d]\n", strncmp("ABCD", "ABCDE", 5));
  strncmp(NULL, "jk", 0);
  printf("TRY 6.13 : [DON'T SEG FAULT]\n");
  strncmp("hj", NULL, 0);
  printf("TRY 6.14 : [DON'T SEG FAULT]\n");
  strncmp("hj", "j", -1);
  printf("TRY 6.15 : [DON'T SEG FAULT]\n");
}

static void	testrindex(void)
{
  printf("TEST 8 - rindex:\n");
  printf("%s\n", rindex("test", 't'));
  printf("%s\n", rindex("test", 't'));
  printf("TRY 8.1 : [%c] [%c]\n", *rindex("1234", '3'), *rindex("1234", '3'));
  printf("TRY 8.2 : [%s] [%s]\n", rindex("azerrozfdifffffpofjnnpininpin", 'f'), rindex("azerrozfdifffffpofjnnpininpin", 'f'));

  if (rindex("1234", 'f') == NULL)
    printf("TRY 8.3 : [NULL] [NULL]\n");
  else
    printf("TRY 8.3 : [NULL] [NOT NULL]\n");
  printf("TRY 8.4 : [%c] [%c]\n", *rindex("1234", '1'), *rindex("1234", '1'));
  printf("TRY 8.5 : [%c] [%c]\n", *rindex("1234", '4'), *rindex("1234", '4'));

  if (rindex(NULL, 'j') == NULL)
    printf("TRY 8.6 : [NULL] [NULL]\n");
  else
    printf("TRY 8.6 : [NULL] [NOT NULL]\n");

  if (rindex("1234", -5) == NULL)
    printf("TRY 8.7 : [NULL] [NULL]\n");
  else
    printf("TRY 8.7 : [NULL] [NOT NULL]\n");

  if (rindex("1234", '3') == rindex("1234", '3'))
    printf("TRY 8.8 : OK\n");
  else
    printf("TRY 8.8 : KO\n");

  if (rindex("azerrozfdifffffpofjnnpininpin", 'f') == rindex("azerrozfdifffffpofjnnpininpin", 'f'))
    printf("TRY 8.9 : OK\n");
  else
    printf("TRY 8.9 : KO\n");

  if (rindex("1234", '1') == rindex("1234", '1'))
    printf("TRY 8.10 : OK\n");
  else
    printf("TRY 8.10 : KO\n");

  if (rindex("1234", '4') == rindex("1234", '4'))
    printf("TRY 8.11 : OK\n");
  else
    printf("TRY 8.11 : KO\n");

  if (rindex("1234", 'f') == rindex("1234", 'f'))
    printf("TRY 8.12 : OK\n");
  else
    printf("TRY 8.12 : KO\n");

  if (rindex("1234", '\0') == rindex("1234", '\0'))
    printf("TRY 8.13 : OK\n");
  else
    printf("TRY 8.13 : KO\n");
  printf("%s %s\n", rindex("Another test...", 'e'), rindex("Another test...", 'e'));
  printf("%s %s\n", rindex("", 0), rindex("", 0));
}

static void	teststrcasecmp(void)
{
  printf("TEST 9 - strcasecmp:\n");
  printf("TRY 9.1 : [%d] [%d]\n", strcasecmp("1234", "1234"), strcasecmp("1234", "1234"));
  printf("TRY 9.2 : [%d] [%d]\n", strcasecmp("abcd", "abcd"), strcasecmp("abcd", "abcd"));
  printf("TRY 9.3 : [%d] [%d]\n", strcasecmp("12345", "1234"), strcasecmp("12345", "1234"));
  printf("TRY 9.4 : [%d] [%d]\n", strcasecmp("abcde", "abcd"), strcasecmp("abcde", "abcd") );
  printf("TRY 9.5 : [%d] [%d]\n", strcasecmp("ABCDE", "ABCD"), strcasecmp("ABCDE", "ABCD"));
  printf("TRY 9.6 : [%d] [%d]\n", strcasecmp("1234", "12345"), strcasecmp("1234", "12345"));
  printf("TRY 9.7 : [%d] [%d]\n", strcasecmp("12345", ""), strcasecmp("12345", ""));
  printf("TRY 9.8 : [%d] [%d]\n", strcasecmp("", "1"), strcasecmp("", "1"));
  printf("TRY 9.9 : [%d] [%d]\n", strcasecmp("abc", "abbcde"), strcasecmp("abc", "abbcde"));
  printf("TRY 9.10 : [%d] [%d]\n", strcasecmp("aBc", "abbbbcde"), strcasecmp("aBc", "abbbbcde"));
  printf("TRY 9.11 : [%d] [%d]\n", strcasecmp("ABC", "abbbbcde"), strcasecmp("ABC", "abbbbcde"));
  printf("TRY 9.12 : [%d] [%d]\n", strcasecmp("abc", "ABBBBCDE"), strcasecmp("abc", "ABBBBCDE"));
  printf("TRY 9.13 : [%d] [%d]\n", strcasecmp("abc", "AbBbbCde"), strcasecmp("abc", "AbBbbCde"));
  strcasecmp(NULL, "jk");
  printf("TRY 9.14 : [DON'T SEG FAULT]\n");
  strcasecmp("hj", NULL);
  printf("TRY 9.15 : [DON'T SEG FAULT]\n");
}

static void	teststrcspn(void)
{
  printf("TEST 10 - strcspn:\n");
  printf("TRY 10.1 : [%ld], [%ld]\n", strcspn("AZCVAZDZD", "3678651"),  strcspn("AZCVAZDZD", "3678651"));
  printf("TRY 10.2 : [%ld], [%ld]\n", strcspn("a1z2e3r4", "fjoijggioja"),  strcspn("a1z2e3r4", "fjoijggioja"));
  printf("TRY 10.3 : [%ld], [%ld]\n", strcspn("123456789", "zertyuikjvvcertyun3"),  strcspn("123456789", "zertyuikjvvcertyun3"));
  printf("TRY 10.4 : [%ld], [%ld]\n", strcspn("aqwzsxedcrfvAZEAAZ", "Z"),  strcspn("aqwzsxedcrfvAZEAAZ", "Z"));
  printf("TRY 10.5 : [%ld], [%ld]\n", strcspn("aihbidhzcsd", "A"),  strcspn("aihbidhzcsd","A"));
  printf("TRY 10.6 : [%ld], [%ld]\n", strcspn("4657879EDI", "%/£%µ"),  strcspn("4657879EDI", "%/£%µ"));
  printf("TRY 10.7 : [%ld], [%ld]\n", strcspn("AZCVAZDZD", ""),  strcspn("AZCVAZDZD", ""));
  printf("TRY 10.8 : [%ld], [%ld]\n", strcspn("", "abc"),  strcspn("", "abc"));
  printf("TRY 10.9 : [%ld], [%ld]\n", strcspn("", ""),  strcspn("", ""));
  if (strcspn(NULL, "Z") == 0)
    printf("TRY 10.10 : [NULL] [NULL]\n");
  else
    printf("TRY 10.10 : [NULL] [NOT NULL]\n");
  if (strcspn("Z", NULL) == 0)
    printf("TRY 10.11 : [NULL] [NULL]\n");
  else
    printf("TRY 10.12 : [NULL] [NOT NULL]\n");
}

static void	teststrstr(void)
{
  printf("TEST 11 - strstr:\n");
  printf("TRY 11.1 : [%s], [%s]\n", strstr("AZCVAZDZD", "A"),  strstr("AZCVAZDZD", "A"));
  printf("TRY 11.2 : [%s], [%s]\n", strstr("a1z2e3r4", "1"),  strstr("a1z2e3r4", "1"));
  printf("TRY 11.3 : [%s], [%s]\n", strstr("123456789", "7"), strstr("123456789", "7"));
  printf("TRY 11.4 : [%s], [%s]\n", strstr("", "abc"), strstr("", "abc"));
  printf("TRY 11.5 : [%s], [%s]\n", strstr("abc", ""), strstr("abc", ""));
  printf("TRY 11.6 : [%s], [%s]\n", strstr("abcde", "cd"), strstr("abcde", "cd"));
  printf("TRY 11.7 : [%s], [%s]\n", strstr("abchabcd", "cd"), strstr("abchabcd", "cd"));
  printf("TRY 11.8 : [%s], [%s]\n", strstr("abcde", "ci"), strstr("abcde", "ci"));
  printf("TRY 11.9 : [%s], [%s]\n", strstr("abcde", "CI"), strstr("abcde", "CI"));
  printf("TRY 11.10 : [%s], [%s]\n", strstr("abcdeabcide", "ci"), strstr("abcdeabcide", "ci"));
  if (strstr(NULL, "Z") == NULL)
    printf("TRY 11.11 : [NULL] [NULL]\n");
  else
    printf("TRY 11.11 : [NULL] [NOT NULL]\n");
  if (strstr("Z", NULL) == NULL)
    printf("TRY 11.12 : [NULL] [NULL]\n");
  else
    printf("TRY 11.12 : [NULL] [NOT NULL]\n");
}

static void	teststrpbrk(void)
{
  printf("TEST 12 - strpbrk:\n");
  printf("%s\n", strpbrk("Pirate", "ter"));
  printf("TRY BIDON1 : [%s], [%s]\n", strpbrk("Bonjour", "no"),  strpbrk("Bonjour", "no"));
  printf("TRY BIDON2 : [%s], [%s]\n", strpbrk("Grosse saucissse", "cso"),  strpbrk("Grosse saucisse", "cso"));
  printf("TRY BIDON3 : [%s], [%s]\n", strpbrk("kebab salade tomate oignon", "zot"),  strpbrk("kebab salade tomate oignon", "zot"));
  printf("TRY 12.1 : [%s], [%s]\n", strpbrk("AZCVAZDZD", "A"),  strpbrk("AZCVAZDZD", "A"));
  printf("TRY 12.2 : [%s], [%s]\n", strpbrk("a1z2e3r4", "1"),  strpbrk("a1z2e3r4", "1"));
  printf("TRY 12.3 : [%s], [%s]\n", strpbrk("123456789", "7"), strpbrk("123456789", "7"));
  printf("TRY 12.4 : [%s], [%s]\n", strpbrk("", "abc"), strpbrk("", "abc"));
  printf("TRY 12.5 : [%s], [%s]\n", strpbrk("abc", ""), strpbrk("abc", ""));
  printf("TRY 12.6 : [%s], [%s]\n", strpbrk("abcde", "cd"), strpbrk("abcde", "cd"));
  printf("TRY 12.7 : [%s], [%s]\n", strpbrk("abchabcd", "cd"), strpbrk("abchabcd", "cd"));
  printf("TRY 12.8 : [%s], [%s]\n", strpbrk("abcde", "ci"), strpbrk("abcde", "ci"));
  printf("TRY 12.9 : [%s], [%s]\n", strpbrk("abcde", "CI"), strpbrk("abcde", "CI"));
  printf("TRY 12.10 : [%s], [%s]\n", strpbrk("abcdeabcide", "ci"), strpbrk("abcdeabcide", "ci"));
  if (strpbrk(NULL, "Z") == NULL)
    printf("TRY 11.11 : [NULL] [NULL]\n");
  else
    printf("TRY 11.11 : [NULL] [NOT NULL]\n");
  if (strpbrk("Z", NULL) == NULL)
    printf("TRY 11.12 : [NULL] [NULL]\n");
  else
    printf("TRY 11.12 : [NULL] [NOT NULL]\n");
}

static void	teststrnlen(void)
{
  printf("TEST 12 - strnlen:\n");
  printf("TRY 12.1 : [%ld] [%ld]\n", strnlen("toto", 4), strnlen("toto", 4));
  printf("TRY 12.2 : [%ld] [%ld]\n", strnlen("toto", 2), strnlen("toto", 2));
  printf("TRY 12.3 : [%ld] [%ld]\n", strnlen("toto", 6), strnlen("toto", 6));
  printf("TRY 12.4 : [%ld] [%ld]\n", strnlen("", 1), strnlen("", 1));
  printf("TRY 12.5 : [%ld] [%ld]\n", strnlen("tototodjkli", 3), strnlen("tototodjkli", 3));
  printf("TRY 12.5 : [%ld] [%ld]\n", strnlen("ehidos,jnzdojcna ozjndaijncaijznd ijnfzijdcnaisjcnzidjcnajocn", 3), strnlen("ehidos,jnzdojcna ozjndaijncaijznd ijnfzijdcnaisjcnzidjcnajocn", 3));
  printf("TRY 12.6 : [%ld] [%ld]\n", strnlen("", 0), strnlen("", 0));
  printf("TRY 12.7 : [%ld] [%ld]\n", strnlen("", -1), strnlen("", -1));
  printf("TRY 12.8 : [0] [%ld]\n", strnlen(NULL, 8));
}

static void	teststrchrnul(void)
{
  printf("TEST 14 - strchrnul:\n");
  printf("TRY 14.1 : [t] [%c]\n", *strchrnul("toto", 't'));
  printf("TRY 14.2 : [o] [%c]\n", *strchrnul("toto", 'o'));
  if (strchrnul("toto", 'k') == strchrnul("toto", 'k'))
    printf("TRY 14.3 : [OK]\n");
  else
    printf("TRY 14.3 : [KO]\n");
  if (strchrnul("", 'k') == strchrnul("", 'k'))
    printf("TRY 14.4 : [OK]\n");
  else
    printf("TRY 14.4 : [KO]\n");
  if (strchrnul(NULL, 'k') == NULL)
    printf("TRY 14.5 : [NULL] [NULL]\n");
  else
    printf("TRY 14.5 : [NULL] [NOT NULL]\n");
  printf("TRY 14.6 : [w] [%c]\n", *strchrnul("aaaaaaaaaaaaaaaaaaaaw", 'w'));
}

static void	teststrrchr(void)
{
  printf("TEST 15 - strrchr:\n");
  if (strrchr("toto", 't') == strrchr("toto", 't'))
    printf("TRY 15.1 : [OK]\n");
  else
    printf("TRY 15.1 : [KO]\n");
  if (strrchr("toto", 'o') == strrchr("toto", 'o'))
    printf("TRY 15.2 : [OK]\n");
  else
    printf("TRY 15.2 : [KO]\n");
  if (strrchr("toto", 'k') == strrchr("toto", 'k'))
    printf("TRY 15.3 : [OK]\n");
  else
    printf("TRY 15.3 : [KO]\n");
  if (strrchr("", 'k') == strrchr("", 'k'))
    printf("TRY 15.4 : [OK]\n");
  else
    printf("TRY 15.4 : [KO]\n");
  if (strrchr(NULL, 'k') == NULL)
    printf("TRY 15.5 : [NULL] [NULL]\n");
  else
    printf("TRY 15.5 : [NULL] [NOT NULL]\n");
}

void	testmemmov(void)
{
  char	test[80];
  char	*test1;
  char	*test2;

  test1 = strdup("rfjdks,dps,");
  test2 = strdup("fvd lkc,zps,pkzd,");

  printf("TEST 7 - memmove:\n");
  memset(test, '\0', 42);
  char  moulinette[42];
  memset(moulinette, 0, 42);
  memmove(moulinette, "1234", 4);
  printf("TRY 7.1 : [%s] [%s]\n", moulinette, (char *)memmove(test, "1234", 4));
  memset(test, '\0', 42);
  memset(moulinette, 0, 42);
  memmove(moulinette, "1234", 8);
  printf("TRY 7.2 : [%s] [%s]\n", moulinette, (char *)memmove(test, "1234", 8));
  memset(moulinette, 0, 42);
  memmove(moulinette, "12", 2);
  memset(test, '\0', 42);
  printf("TRY 7.3 : [%s] [%s]\n", moulinette, (char *)memmove(test, "12", 2));
  memset(moulinette, 0, 42);
  memmove(moulinette, "1234", 2);
  memset(test, '\0', 42);
  printf("TRY 7.4 : [%s] [%s]\n", moulinette, (char *)memmove(test, "1234", 2));
  memset(moulinette, 0, 42);
  memset(test, '\0', 42);
  if (memmove(NULL, "11", 2) == NULL)
    printf("TRY 7.5 : [NULL] [NULL]\n");
  else
    printf("TRY 7.5 : [NULL] [NOT NULL]\n");
  memset(test, '\0', 42);
  memmove(test, NULL, 67);
  printf("TRY 7.6 : [DON'T SEG FAULT]\n");
  memset(test, '\0', 42);
  memmove(test, "j", -1);
  printf("TRY 7.7 : [DON'T SEG FAULT]\n");
  printf("TEST 7.8 : [%s]\n", memmove(test1, test2, 10) == memmove(test1, test2, 10) ? "OK" : "KO");
  printf("TEST 7.9 : [%s]\n", strncmp(memmove(test1, test2, 10), memmove(test1, test2, 10), 10) == 0 ? "OK" : "KO");
  printf("TEST 7.10 : [%s]\n", memmove(test1, test2, 1) == memmove(test1, test2, 1) ? "OK" : "KO");
  printf("TEST 7.11 : [%s]\n", strncmp(memmove(test1, test2, 1), memmove(test1, test2, 1), 1) == 0 ? "OK" : "KO");
  char *s1 = strdup("picapica");
  char *s2 = strdup("picapica");
  printf("%s %s\n", memmove(s1 + 1, s1, 2), memmove(s2 + 1, s2, 2));
}

int	main(void)
{
  printf("mymoulinette :\n");

  teststrchr();
/*   teststrlen();
  testmemset();
  testmemcpy();
  teststrcmp();
  teststrncmp();
  testmemmov();
  testrindex();
  teststrcasecmp();
  teststrcspn();
  teststrstr();
  teststrpbrk();
  teststrnlen();
  testindex();
  teststrchrnul();
  teststrrchr(); */
  return (0);
}