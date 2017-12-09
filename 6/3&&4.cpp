#include <iostream>
#include <malloc.h>
#include <queue>

using namespace std;
bool vis[7];
class tree
{
public:
    int data;
    tree* vp;
    tree* hp;
};
void visit(tree *t)
{queue<tree *>q;
    q.push(t);
  while(!q.empty())
  {  t=q.front();
      if(vis[t->data]== false)
      {
          vis[t->data] = true;
          printf("%d ", t->data);
      }
      q.pop();
      if(t->vp!=NULL)
      {
          t = t->vp;
          q.push(t);
      }

      while(t->hp!=NULL)
      {
          q.push(t->hp);
          t=t->hp;
      }

  }


}
int main()
{
    tree *a, *b, *c, *d, *e, *f, *g;
    a = (tree *)malloc(sizeof(tree));
    b = (tree *)malloc(sizeof(tree));
    c = (tree *)malloc(sizeof(tree));
    d = (tree *)malloc(sizeof(tree));
    e = (tree *)malloc(sizeof(tree));
    f = (tree *)malloc(sizeof(tree));
    g = (tree *)malloc(sizeof(tree));
    a->data = 1;
    b->data = 2;
    c->data = 3;
    d->data = 4;
    e->data = 5;
    f->data = 6;
    g->data = 7;
    a->vp = b;
    a->hp = NULL;
    b->vp = d;
    b->hp = c;
    c->vp = NULL;
    c->hp = NULL;
    d->vp = NULL;
    d->hp = e;
    e->vp = g;
    e->hp = f;
    f->vp = NULL;
    f->hp = NULL;
    g->vp = NULL;
    g->hp = NULL;
    visit(a);
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);
    free(g);



}
