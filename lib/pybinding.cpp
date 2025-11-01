// pybindig.cpp
#include <pybind11/pybind11.h>
#include "./jogo/jogo.hpp"

namespace py = pybind11;

PYBIND11_MODULE(jogo, m){
    m.doc() = "Classe jogo";

    py::module_ lib = m.def_submodule("lib", "Namespace LibJogo");

    py::class_<LibJogo::Jogo>(lib, "Jogo")
        .def(py::init<>())
        .def("inicializa", &LibJogo::Jogo::inicializa, "Inicializa o jogo")
        .def("desenhaMapa", &LibJogo::Jogo::desenha_mapa, "Imprime o mapa")
        .def("atualiza", &LibJogo::Jogo::atualiza_carros, "Atualiza a posição do carro");
}