//
// Created by Sebastian Donoso on 15-10-18.
//

#ifndef T1_COMERCIALES_PATHFILES_H
#define T1_COMERCIALES_PATHFILES_H

#include <string>
#include <vector>

void agregar_archivo(const std::string &dirname, const std::string &name, std::vector<std::string> &list);

std::vector<std::string> listar_archivos(const std::string &dirname);

#endif //T1_COMERCIALES_PATHFILES_H
