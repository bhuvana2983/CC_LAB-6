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
                sh 'docker rm -f backend || true'
                sh 'docker run -d --name backend backend-image'
            }
        }

        stage('Build NGINX Image') {
            steps {
                sh 'docker build -t nginx-image ./nginx'
            }
        }

        stage('Run NGINX Container') {
            steps {
                sh 'docker rm -f nginx-server || true'
                sh '''
                docker run -d \
                --name nginx-server \
                --link backend \
                -p 8081:80 \
                nginx-image
                '''
            }
        }
    }
}
