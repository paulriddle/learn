package main

import (
	"html/template"
	"io/ioutil"
	"log"
	"net/http"
)

func main() {
	mux := http.NewServeMux()
	mux.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		if r.Method == "GET" {
			templ, err := template.ParseFiles("page.html")
			if err != nil {
				log.Fatalln(err)
			}
			templ.Execute(w, nil)
		} else {
			body, err := ioutil.ReadAll(r.Body)
			if err != nil {
				log.Fatalln(err)
			}
			log.Println(string(body))
			w.Write(body)
		}
	})
	log.Println("Listening on http://localhost:9000")
	log.Fatal(http.ListenAndServe(":9000", mux))
}
