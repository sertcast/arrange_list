//
//  arrange_list.h
//  arrange_list
//
//  Created by Mert Kaya on 2017-10-07.
//  Copyright © 2017 Mert Kaya. All rights reserved.
//

#ifndef arrange_list_h
#define arrange_list_h

#include "linked_list.h"
double *parse_file(char*filename, int *psize);
void arrange_list(double *list, int *psize);
#endif /* arrange_list_h */
