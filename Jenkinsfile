#!groovy
node {

	stage('Test') {
		// Command
		git credentialsId: '3004dcb7-f66a-4e59-a2d3-6c3da31186ff', url: 'https://github.com/Northeastern-Micromouse/MicroMouse2017'
		echo 'Running ${env.BUILD_ID} on ${env.JENKINS_URL}'
		sh 'rm -rf builds'
		sh 'mkdir builds'
		sh 'bazel test src/test/c/com/micromouse/... > builds/output.bazel'
		echo '-----------------------Build results----------------------------'
		sh 'cat builds/output.bazel'
	}
}
