package main

import "fmt"

func arredonda(v int) int {
	x := (v / 5) * 5
	if v % 5 > 2 {
		x = (v / 5 + 1) * 5
	}
	return x
}

func main() {
	var T int
	soma := 0
	soma_arredondada := 0
	fmt.Scanln(&T)
	for t := 0; t < T; t++ {
		var valor int
		var acao string

		fmt.Scanln(&valor, &acao)
		soma += valor

		if acao == "C" {
			soma_arredondada += valor
		} else if acao == "D" {
			soma_arredondada += arredonda(valor)
		}
	}

	fmt.Println(soma, soma_arredondada - soma)
}