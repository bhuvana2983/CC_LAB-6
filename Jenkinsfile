pipeline {
    agent any

    stages {

        stage('Build Backend Image') {
            steps {
                sh 'docker build -t backend-image ./backend'
            }
        }

        stage('Run Backend Container') {
            steps {
                sh 'docker run -d --name backend backend-image'
            }
        }

        stage('Run NGINX Container') {
            steps {
                sh '''
                docker run -d \
                --name nginx-server \
                --link backend \
                -p 8081:80 \
                -v $(pwd)/nginx/default.conf:/etc/nginx/conf.d/default.conf \
                nginx
                '''
            }
        }
    }
}
