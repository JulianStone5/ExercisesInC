#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>

void iterator(gpointer key, gpointer value, gpointer user_data) {
  printf(user_data,key,GPOINTER_TO_INT(value));
}

int main() {
  FILE *f = fopen("test.txt","r");
  char buff[255] = "";
  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
  while(fscanf(f, "%s", buff) == 1) {
    gint *num = (gint*)g_hash_table_lookup(hash,buff);
    if(num == NULL) {
      g_hash_table_insert(hash,g_strdup(buff),GINT_TO_POINTER(1));
    } else {
      int n = GPOINTER_TO_INT(num);
      g_hash_table_replace(hash,g_strdup(buff),GINT_TO_POINTER(n+1));
    }
  }
  g_hash_table_foreach(hash, (GHFunc)iterator, "%s: %d\n");
  fclose(f);
  return 0;
}
